#include <iostream>

using namespace std;

int main()
{

     double number;

     int nn, m, d, c, l, x, v, i, n;

     cout << "Enter decimal number:";

     cin >> number;

     nn = (int)number;

     m = nn / 1000;

     d = ((nn % 1000) / 500);

     c = ((nn % 500) / 100);

     l = ((nn % 100) / 50);

     x = ((nn % 50) / 10);

     v = ((nn % 10) / 5);

     i = (nn % 5);

     n = m + d + c + l + x + v + i;

     cout << number << " is ";

     while (n > 0)

     {

          for (; m > 0; m--)

               cout << "M";

          for (; d > 0; d--)

               cout << "D";

          for (; c > 0; c--)

               cout << "C";

          for (; l > 0; l--)

               cout << "L";

          for (; x > 0; x--)

               cout << "X";

          for (; v > 0; v--)

               cout << "V";

          for (; i > 0; i--)

               cout << "I";

          n--;
     }

     return 0;
}