
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
      int length, mult = 1, input_num;

      cout << "Enter the length of the sequence: ";
      cin >> length;
      cout << "Please enter your sequence and separate with space: ";
      //get the product of all input numbers

      for (int i = 0; i < length; ++i)
      {
            cin >> input_num;
            mult *= input_num;
      }

      //apply the pow function and print out the resutls
      cout << "The geometric mean is : " << pow(mult, (float)1 / length) << endl;

      return 0;
}
