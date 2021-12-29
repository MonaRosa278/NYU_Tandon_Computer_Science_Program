
#include <iostream>
using namespace std;
// define all the constant values 
const int QUARTER_TO_CENTS = 25;
const int DIME_TO_CENTS = 10;
const int NICKEL_TO_CENTS = 5;
const int PENNY_TO_CENTS = 1;

int main()
{
    int quarters, dimes, nickels, pennies;
    int cents_in_total;
    int cents, dollars;
   
    // promote user input 
    cout << "Please enter number of coins: " << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies; ";
    cin >> pennies;
   
    // convert all the given money into cents then calculate the numbers of dollars and cents
    cents_in_total = quarters * QUARTER_TO_CENTS + dimes * DIME_TO_CENTS + nickels * NICKEL_TO_CENTS + pennies * PENNY_TO_CENTS;
    dollars = cents_in_total / 100;
    cents = cents_in_total % 100;
    cout << "The toal is " << dollars << " dollars and " << cents << " cents " << endl;
}
