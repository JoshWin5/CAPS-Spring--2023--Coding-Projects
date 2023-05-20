#include <arduino-timer.h>
#include <HardwareSerial.h>

#define SYSTEM_OFF_STATE 0
#define SYSTEM_BLE_INIT_STATE 1
#define SYSTEM_ON_STATE 2
#define SYSTEM_SHUTDOWN_STATE 3
static u8 system_state = SYSTEM_OFF_STATE;

#define BLE_INIT 0
#define BLE_ESC 1
#define BLE_ATTENTION 2
#define BLE_UART_MODE 3
#define BLE_DTR_MODE 4
#define BLE_LOCAL_NAME 5
#define BLE_AD_DATA 6
#define BLE_DATA_MODE 7
#define BLE_INITIALIZED 8

static u8 init_state = BLE_INIT;

static u8 bleSendEscStr[]={"+++"};
static u8 bleSetUartModeStr[]={"AT+UMRS=115200, 2, 8, 1, 1, 1/r"};
static u8 bleSendDTRIgnoreStr[] = "AT&D1\r";
static u8 bleSetDataModeStr[]={"AT+UMSM=1/r"};
static u8 bleSendAttentionStr[]={"AT/r"};
static u8 bleSetLocalNameStr[]={"AT+UBTLN=CLAMPMITTER/r"};
static u8 bleSetAdDataStr[]={"AT+UBTAD=07434c414d504d4954544552/r"}; 

static u8 BLE_mode = 0;
static u16 ble_cntr = 25000;
static u8 ble_init = 0;
static u8 BLE_link = 0;

auto timer = timer_create_default();
unsigned long minutes = 6000;

void setup()
{
Serial.begin(115200);
pinMode(11, OUTPUT);
timer.every(10000, toggle_led);
for(;;)
{
switch(system_state)
{
  case SYSTEM_OFF_STATE:
  default:
  break;
  case SYSTEM_BLE_INIT_STATE:
  {
    static u8 rxstr[32];
    static u8 len = 0;

    if (Serial.available())
    {
      u8 c = Serial.read();
      if((c >='a') && (c <= 'z')) c &= 0xDF;
      if ((c == 0x0D) || (c == 0x0A))
      {
        len = 0; 
        if(init_state == BLE_INITIALIZED)
        {}else
        {
          if ((rxstr[0] == 'O')&&(rxstr[1] == 'K'))
          {
            BLE_link = 1;
          }
          if((rxstr[0] == '+')&&(rxstr[1] == 'S')&&(rxstr[2] == 'T')&&(rxstr[3] == 'A')&&(rxstr[4] == 'R')&&(rxstr[5] == 'T')&&(rxstr[6] == 'U')&&(rxstr[7] == 'P'))
          {
            delay (1000);
            init_state = BLE_DTR_MODE; 
            TransmitStr(bleSendDTRIgnoreStr);
          }
          if((rxstr[0] == 'E')&&(rxstr[1] == 'R')&&(rxstr[2] == 'R')&&(rxstr[3] == 'O')&&(rxstr[4] == 'R'))
          {
            delay (2000);
            init_state = BLE_ATTENTION; 
            TransmitStr(bleSendAttentionStr);
          }
        }
      }
      else
      {
        rxstr[len] = (char) c ;
        len++;
      }
    }
    switch(init_state)
    {
      case BLE_INIT:
      if(!ble_cntr)
      {
        ble_cntr = 10000;
        init_state = BLE_ESC;
        TransmitStr(bleSendEscStr);
      }
      break;
      case BLE_ESC:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_ATTENTION; 
      TransmitStr(bleSendAttentionStr);
      break;
      case BLE_ATTENTION:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_LOCAL_NAME;  
      TransmitStr(bleSetLocalNameStr);
      break;
      case BLE_DTR_MODE:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_LOCAL_NAME;  
      TransmitStr(bleSetLocalNameStr);
      break;
      case BLE_LOCAL_NAME:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_AD_DATA;  
      TransmitStr(bleSetAdDataStr);
      break;
      case BLE_AD_DATA:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_DATA_MODE;
      TransmitStr(bleSetDataModeStr);
      break;
      case BLE_DATA_MODE:
      if(BLE_link) BLE_link = 0;
      init_state = BLE_INITIALIZED;
      break;
      case BLE_INITIALIZED:
      system_state = SYSTEM_ON_STATE;
      BLE_mode = 1;
    }

  }
}
}
}

bool toggle_led(void *) 
{
  digitalWrite(11, !digitalRead(11)); 
  return true; 
}

void TransmitStr(u8 *str)
{
u8 c;
while(c = *str++)
 {
 if(c == 0x0D) Serial.write(0x0D);
 else if(c == 0x0A) Serial.write(0x0A);
 else Serial.write(c);
 } 
}

void loop() 
{
if (millis() < minutes * 15)
{timer.tick(); }
else{}
}
