
#include <iostream>
using namespace std;

//define a function to convert decimal to binary
void DecimalToBinary(int intInput)
{
    long long binaryNumber = 0;
    int remainder;
    int i = 1;
    int num = intInput;

    while (num != 0)
    {
        remainder = num % 2;
        num /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    cout << "The binary representation of " << intInput << " is " << binaryNumber << endl;
}

int main()
{
    int decimal_num;
    cout << "Please enter a decimal: ";

    cin >> decimal_num;
    DecimalToBinary(decimal_num); // call the function
    return 0;
}