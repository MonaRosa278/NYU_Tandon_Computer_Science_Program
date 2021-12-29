
/*
1. define all the constant values used in this program
2. get users inputs 
3. switch statement 
 */
#include <iostream>

using namespace std;

// define constant values
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{

    double real_number, fractpart, intpart;
    int round_method;

    //get all the users inputs
    cout << "Please enter a real number: ";
    cin >> real_number;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number " << endl;
    cin >> round_method;

    //use the modf method to seperate integer part and fractinal part
    fractpart = modf(real_number, &intpart);
    switch (round_method)
    {
    case 1:
        cout << intpart << endl;
        break;

    case 2:
        cout << intpart + 1 << endl;
        break;

    case 3:
        if (real_number - intpart <= .5)
        {
            cout << intpart << endl;
        }
        else
        {
            cout << intpart + 1 << endl;
        }
    }
    return 0;
}