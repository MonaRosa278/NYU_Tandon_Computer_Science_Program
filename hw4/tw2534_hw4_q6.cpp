
#include <iostream>
#include <cmath>
using namespace std;

//define a function to count the number of odd digits and even digits
void digit_classify(int num)
{

     int digit, odd_count, even_count;

     for (int i = 1; i <= num; ++i)
     {

          int j = i;
          even_count = 0;
          odd_count = 0;

          while (j > 0)
          {
               digit = j % 10;
               j /= 10;
               if (digit % 2 == 0)
                    even_count++;
               else
                    odd_count++;
          }
          if (even_count > odd_count)

               cout << i << endl;
     }
}

int main()
{
     int num;
     cout << "Please enter a positive integer: ";
     cin >> num;
     digit_classify(num);

     return 0;
}