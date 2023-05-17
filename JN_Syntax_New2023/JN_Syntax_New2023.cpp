//1. Data Type: Integers
//Define: Stores numbers without decimals 
//int salary = 85000;

//2. Data Type: Float
//Define: Used to define number values
//float area = 64.74;

//3. Data Type: Double
// Define: Can represent any numerical value, including values 
//double volume = 134.64534;

//4. Data Type: Characters
//Define: Used to store letters
//char test = 'h';

//5. Data Type: Wide Characters
//Define: Internal representation of characters
//wchar_t test = 'h';

//6. Data Type: Boolean
//Define: Can make values true or false
//bool cond = false;

//7. Data Type: Void
//Define: Specifies that a function doesn't return a value 
//void;

// Input and Output
#include <iostream>
#include <string>
using namespace std;
int main()
{
	std::string firstName;
	std::cout << "Type your first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Your name is: " << firstName << endl;
	
	int num1 , num2, sum;
	std:: cout << "Enter two integers: ";
	std:: cin >> num1 >> num2;
	sum = num1 + num2;
	std:: cout << num1 << " + " << num2 << " = " << sum;
	return 0;
}

