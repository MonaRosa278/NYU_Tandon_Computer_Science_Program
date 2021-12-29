
#include <iostream>
using namespace std;
int main()
{
     int input_num1, input_num2;
     int i = 1;
     int j = 1;

     //for the while loop
     cout << "Please enter a positive integer for the while loop: ";
     cin >> input_num1;

     while (input_num1 > 0)
     {
          cout << i * 2 << endl;

          input_num1--;

          i++;
     }

     //for the for loop
     cout << "Please enter another positive integer for the for loop: ";
     cin >> input_num2;

     for (int j = 1; j <= input_num2; ++j)
     {
          cout << j * 2 << endl;
     }

     return 0;
}