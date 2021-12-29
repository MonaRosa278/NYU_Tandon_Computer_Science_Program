
/*
1. define two bool functions to check if the users inputs are valid
2. define a function to decide the rate per min for the call
3. get users inputs 
 */

#include <iostream>
#include <string>

using namespace std;

string const DAYS_OF_WEEK[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

bool Is_valid_day(string day)
{
    for (int i = 0; i < 7; ++i)
    {
        if (day == DAYS_OF_WEEK[i])
        {
            return true;
        }
    }
    return false;
}

bool Is_valid_time(int hrs, char colon, int mins)
{
    if ((hrs > 0 && hrs < 24) && (mins >= 0 && mins < 60))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// define a function to decide the rate per min depends on the users input
double rate_per_min(string day, int hrs, char colon, int mins)
{
    double rate_per_min;
    if (day == "Sa" || day == "Su")
    {
        rate_per_min = .15;
    }
    else
    {

        if (hrs >= 8 && hrs <= 18)
        {

            rate_per_min = .4;
        }
        else
        {

            rate_per_min = .25;
        }
    }
    return rate_per_min;
}

int main()
{
    //    define all the variables
    string day;
    int hrs, mins, call_length;
    char colon;
    double total_cost;

    //    validate users day input with redefined function
    cout << "Please enter a day with the first two characters(e.g. Mo, Tu): ";
    cin >> day;

    //    validate users 24-notation time input with predefined function

    cout << "Please enter a 24-notation time and separate with a colon: ";
    cin >> hrs >> colon >> mins;

    //      validate users call length input
    cout << "Please enter your call length(in mins): ";
    cin >> call_length;

    total_cost = rate_per_min(day, hrs, colon, mins) * call_length;
    cout << "The total cost would be: " << total_cost << endl;

    return 0;
}
