
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
     int input_num;
     cout << "Enter an integer: ";
     cin >> input_num;

     for (int i = 1; i <= input_num; ++i)
     {
          for (int k = 1; k <= i; ++k)
          {
               cout << "  ";
          }

          for (int j = i; j <= input_num; ++j)
          {
               cout << "* ";
          }
          for (int j = i; j < input_num; ++j)
          {
               cout << "* ";
          }

          cout << endl;
     }
     for (int i = 1; i <= input_num; ++i)
     {
          for (int k = i; k <= input_num; ++k)
          {
               cout << "  ";
          }
          for (int j = 1; j <= i; ++j)
          {
               cout << "* ";
          }
          for (int j = 1; j < i; ++j)
          {
               cout << "* ";
          }

          cout << endl;
     }
     return 0;
}