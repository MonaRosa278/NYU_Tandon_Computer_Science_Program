#include <iostream>
using namespace std;

// define the divisor function
void printDivisors(int num)
{

      for (int i = 1; i <= num; ++i)
      {
            if (num % i == 0)
            {
                  cout << i << " ";
            }
      }
}
int main()
{
      //get users input
      int num;
      cout << "Please enter a positive integer >= 2: ";
      cin >> num;
      printDivisors(num);
}
