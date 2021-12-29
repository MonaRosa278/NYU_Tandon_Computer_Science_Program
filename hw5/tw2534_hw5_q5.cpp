#include <iostream>
using namespace std;

int outCountDivs = 0;
int outSumDivs = 0;

//define the function to check the input number of proper devisor and the sum of devisors
void analyzeDividors(int num, int &outCountDivs, int &outSumDivs)
{
      for (int j = 2; j <= sqrt(num); j++)
      {
            if (num % j == 0)
            {
                  if (j == (num / j))
                  {
                        outSumDivs = outSumDivs + j;
                        outCountDivs = outCountDivs + 1;
                  }

                  else
                  {
                        outSumDivs = outSumDivs + j + num / j;
                        outCountDivs = outCountDivs + 2;
                  }
            }
      }
      outSumDivs = outSumDivs + 1;
      outCountDivs = outCountDivs + 1;
}

//check if its a prefect number;
bool isPerfect(int num)
{
      if (num == outSumDivs)
      {

            return true;
      }

      else
      {
            return false;
      }
}

int main()
{
      int M;
      // User input
      cout << "Enter a positive integer >= 2: ";
      cin >> M;
      // Finding perfect number
      cout << "The perfect numbers between 2 and " << M << " are:" << endl;
      for (int i = 2; i <= M; i++)
      {
            outCountDivs = 0;
            outSumDivs = 0;
            analyzeDividors(i, outCountDivs, outSumDivs);

            if (isPerfect(i))
            {
                  cout << i << " ";
            }
      }
      cout << endl;
      // Finding pair of amicable numbers
      cout << "Amicable numbers: " << endl;

      for (int j = 2; j <= M; j++)
      {
            outCountDivs = 0;
            outSumDivs = 0;

            analyzeDividors(j, outCountDivs, outSumDivs);
            int sum1 = outSumDivs;

            outCountDivs = 0;
            outSumDivs = 0;

            analyzeDividors(sum1, outCountDivs, outSumDivs);
            int sum2 = outSumDivs;

            if (j < sum1 && (sum1 <= M) && sum2 == j)
            {
                  cout << j << " " << sum1 << endl;
            }
      }
      cout << endl;

      return 0;
}
