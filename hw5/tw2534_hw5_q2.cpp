
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol)
{
      //print trinagle with spaces

      for (int i = 1; i <= n; ++i)
      {

            for (int a = 1; a <= 4; ++a)
            {
                  cout << " ";
            }

            for (int k = i; k <= n + 1; ++k)
            {
                  cout << "  ";
            }
            for (int m = 1; m <= i; ++m)
            {
                  cout << " *";
            }
            for (int n = 1; n < i; ++n)
            {
                  cout << " *";
            }

            cout << endl;
      }
}

//define the function to print pinetree
void printPineTree(int n, char symbol)
{
      for (int i = 1; i <= n; ++i)
      {

            for (int j = 1; j <= i + 1; ++j)
            {
                  for (int z = i; z <= n; ++z)
                  {
                        cout << "  ";
                  }
                  for (int y = i; y <= n; ++y)
                  {
                        cout << " ";
                  }
                  for (int x = j; x <= i + 1; ++x)
                  {
                        cout << "   ";
                  }

                  for (int a = 1; a <= j; ++a)
                  {
                        cout << " # ";
                  }
                  for (int b = 1; b < j; ++b)
                  {
                        cout << " # ";
                  }
                  cout << endl;
            }

            cout << endl;
      }

      cout << endl;
}

int main()
{
      int n, m, num_tree;
      char symbol, symbol_1;
      cout << "Please enter the lines, number of spaces, symbo and separate ";
      cout << "with a space: ";
      cin >> n >> m >> symbol;
      //printPineTree(n, symbol);
      printShiftedTriangle(n, m, symbol);
      cout << "------------------------------" << endl;
      cout << endl;

      printPineTree(n, symbol);

      return 0;
}