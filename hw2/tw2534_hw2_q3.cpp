
#include <iostream>
using namespace std;
//define all the constant values 
const int DAY_TO_MINS = 1440;
const int HRS_TO_MINS = 60;

int main(){

    int days_john_work, hrs_john_work, min_john_work;
    int days_bill_work, hrs_bill_work, min_bill_work;
    int john_work_in_mins, bill_work_in_mins, both_work_in_mins;
    int together_in_days, together_in_hrs, together_in_mins;
    
    //promote user input
    cout << "Please	enter the number of days John has worked:";
    cin >> days_john_work;
    cout << "Please	enter the number of hours John has worked:";
    cin >> hrs_john_work;
    cout << "Please	enter the number of minutes John has worked:";
    cin >> min_john_work;
    
    cout << "Please	enter the number of days Bill has worked:";
    cin >> days_bill_work;
    cout << "Please	enter the number of hours Bill has worked:";
    cin >> hrs_bill_work;
    cout << "Please	enter the number of minutes John has worked:";
    cin >> min_bill_work;
    
    //convert their work time into minutes and combine the time
    john_work_in_mins = days_john_work * DAY_TO_MINS + hrs_john_work * HRS_TO_MINS + min_john_work;
    bill_work_in_mins = days_bill_work * DAY_TO_MINS + hrs_bill_work * HRS_TO_MINS + min_bill_work;
    both_work_in_mins = john_work_in_mins + bill_work_in_mins;
    
    //convert combined work minutes into days, hours and minutes 
    together_in_days = both_work_in_mins /DAY_TO_MINS;
    together_in_hrs = (both_work_in_mins % DAY_TO_MINS) / HRS_TO_MINS;
    together_in_mins= both_work_in_mins - together_in_days * DAY_TO_MINS - together_in_hrs * HRS_TO_MINS;
    cout << "The total time	both of	them worked together is: " << together_in_days << " days, " ;
    cout << together_in_hrs << " hours, and " << together_in_mins << " minutes. ";

}
