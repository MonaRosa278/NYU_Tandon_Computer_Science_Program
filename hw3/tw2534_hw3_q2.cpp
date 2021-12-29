
/*
1. get users input and check if they are valid
2. flow control
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string name;
    int graduation_year, current_year;

    // get all the input from users and check if they are valid
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> graduation_year;

    cout << "Please enter current year: ";
    cin >> current_year;

    //flow control
    if (current_year == graduation_year)
    {

        cout << name << ", you are Gradauted" << endl;
    }
    else if (graduation_year - current_year == 4)
    {

        cout << name << ", you are a Freshman" << endl;
    }
    else if (current_year - graduation_year == 3)
    {

        cout << name << ", you are a Sophomore" << endl;
    }
    else if (current_year - graduation_year == 2)
    {

        cout << name << ", you are a Junior" << endl;
    }
    else if (current_year - graduation_year == 1)
    {

        cout << name << ", you are a Senior" << endl;
    }
    else
    {
        cout << "Your inputs are incorrect! " << endl;
    }

    return 0;
}
