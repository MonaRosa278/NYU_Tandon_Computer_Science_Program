
#include <iostream>
using namespace std;
// define all the constant values
const int DOLLAR_TO_CENTS = 100;
const int QUARTER_TO_CENTS = 25;
const int DIME_TO_CENTS = 10;
const int NICKEL_TO_CENTS = 5;
const int PENNY_TO_CENTS = 1;

int main(){

    int input_dollars, input_cents;
    int cents_in_total, quarters, dimes, nickels, pennies;

    //promote user input and save them separatively 
    cout << "Please enter yout amount in the format of dollars and cents separated by a space: ";
    cin >> input_dollars >> input_cents;
    
    //convert the given money to cents then calculate maximium number of quarter, dime, nickel and  penny
    cents_in_total = input_dollars * DOLLAR_TO_CENTS + input_cents;
    quarters = cents_in_total / QUARTER_TO_CENTS;
    dimes = (cents_in_total % QUARTER_TO_CENTS) / DIME_TO_CENTS;
    nickels = (cents_in_total - quarters * QUARTER_TO_CENTS - dimes * DIME_TO_CENTS) / NICKEL_TO_CENTS;
    pennies = (cents_in_total - quarters * QUARTER_TO_CENTS - dimes * DIME_TO_CENTS - nickels * NICKEL_TO_CENTS) / PENNY_TO_CENTS;
    cout << input_dollars << " dollars " << input_cents << " cents are: " << endl;
    cout << quarters << " quaters, " << dimes << " dimes, " << nickels <<" nickels, and " << pennies <<" pennies "<<endl;
    
    
}