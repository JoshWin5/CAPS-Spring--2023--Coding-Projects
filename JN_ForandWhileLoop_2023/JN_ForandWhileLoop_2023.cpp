#include <iostream>
using namespace std;

//While Loop for Evens
void printEvenNumbers(int N)
{ 
    cout << "Even: ";
    int i = 2;
    while (i <= 100 * N){
        if (i % 2 == 0)
        cout << i  << " ";
        i++;
    }
}

// For Loop for Odds
void printOddNumbers(int N)
{
    cout << "\nOdd: ";
    for (int i = 1; i <= 100 * N; i++) {

        if (i % 2 != 0)
            cout << i << " ";
    }
}

int main()
{
    int N = 1;

    printEvenNumbers(N);
    printOddNumbers(N);
    return 0;
}





