#include <iostream>
using namespace std;

//define the funciton
double eApprox(int n)

{
       double sum = 1.00;

       double x = 1.00;

       for (int i = n - 1; i > 0; --i)

              sum = 1 + x * sum / i;

       return sum;
}

int main()
{
       cout.precision(30);
       for (int n = 1; n <= 15; n++)
       {
              cout << "n = " << n << '\t' << eApprox(n) << endl;
       }

       return 0;
}
