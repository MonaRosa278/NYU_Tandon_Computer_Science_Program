#include <iostream>
#include <cmath>
using namespace std;

int main()
{
      int length = 0, input_num, mult = 1;
      cout << "Please enter a non-empty sequence of positive integers and separate with space, end your sequence by typing -1: ";

      while (1)
      {
            cin >> input_num;
            if (input_num == -1)
            {
                  break;
            }
            length++;
            mult *= input_num;
      }
      cout << "The Geometric mean is: " << pow(mult, (float)1 / length) << endl;
      return 0;
}