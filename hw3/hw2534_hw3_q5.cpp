
/*
1. get users inputs and covert them into kilos and meters
2. flow control to check the MBI range
 */

#include <iostream>

using namespace std;

int main()
{
    int pounds, inches;
    double kilos, meters;
    double BMI;
    string weight_status;

    cout << "Please enter weight(in pounds): ";
    cin >> pounds;
    cout << "Please enter height(in inches): ";
    cin >> inches;

    //convert pounds, inches into kilos and meters for the BMI formula
    kilos = pounds * 0.453592;
    meters = inches * 0.0254;

    //get the BMI vlaue with the formila
    BMI = kilos / (meters * meters);
    if (BMI < 18.5)
    {
        weight_status = "Underweight";
    }
    else if (BMI >= 18.5 && BMI < 25)
    {
        weight_status = "Normal";
    }
    else if (BMI >= 25 && BMI < 30)
    {
        weight_status = "Overweight";
    }
    else if (BMI >= 30)
    {
        weight_status = "Obese";
    }

    cout << "The weight status is: " << weight_status << endl;

    return 0;
}
