
#include <iostream>
using namespace std;

int main(){
    
    int num1, num2;
    int num1_plus_num2;
    int num1_minus_num2;
    int num1_times_num2;
    float num1_div_num2_float;
    int num1_div_num2;
    int num1_mod_num2;
    
    //promte two integers and save them separatively 
    cout << "Please enter two positive integers, separated by a space: ";
    cin >> num1 >> num2;
    num1_plus_num2 = num1 + num2;
    num1_minus_num2 = num1 - num2;
    num1_times_num2 = num1 * num2;
    //need to cast num1 and num2 to float 
    num1_div_num2 = num1 / num2;
    num1_div_num2_float = (float) num1 / (float) num2;
    num1_mod_num2 = num1 % num2;
    
    cout << num1 << " + " << num2  << " = " << num1_plus_num2 << endl; 
    cout << num1 << " - " << num2 << " = " << num1_minus_num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1_times_num2  << endl;
    cout << num1 << " div " << num2 << " = " << num1_div_num2_float << endl;
    cout << num1 << " / " << num2 << " = " << num1_div_num2 << endl;
    cout <<  num1 << " mod " << num2 << " = " << num1_mod_num2 << endl;
}