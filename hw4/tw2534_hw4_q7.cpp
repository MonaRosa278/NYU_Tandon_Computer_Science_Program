
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
     int j = 1;
     int row_num;
     cout << "Please enter a positive integer: ";
     cin >> row_num;

     for (int i = 1; i <= row_num; ++i)
     {
          for (int j = 1; j <= row_num; ++j)
          {
               cout << j * i << " ";
               cout << "\t";
          }
          cout << endl;
     }
     return 0;
}