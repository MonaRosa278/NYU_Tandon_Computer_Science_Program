#include <iostream>
#include <string>
using namespace std;

//a
void printTriangle(int n)
{
      if (n == 1)
      {
            cout << "*" << endl;
      }
      else
      {
            printTriangle(n - 1);
            for (int i = 0; i < n; i++)
            {
                  cout << "*";
            }
            cout << endl;
      }
}
//b
void printOpositeTriangles(int n)
{
      if (n == 1)
      {
            cout << "*\n*\n";
      }
      else
      {
            for (int i = 0; i < n; i++)
            {
                  cout << "*";
            }
            cout << endl;
            printOpositeTriangles(n - 1);
            for (int i = 0; i < n; i++)
            {
                  cout << "*";
            }
            cout << endl;
      }
}
//c
void printRuler(int n)
{
      if (n == 1)
      {
            cout << "-\n";
      }
      else
      {
            printRuler(n - 1);
            for (int i = 0; i < n; i++)

            {
                  cout << "-";
            }
            cout << endl;
            printRuler(n - 1);
      }
}
int main()
{
      cout << "-----------PrintTriangle-----------\n";
      printTriangle(4);
      cout << "-----------PrintOppsiteTrangle-----------\n";
      printOpositeTriangles(4);
      cout << "-------------printRuler----------------\n";
      printRuler(4);
      return 0;
}