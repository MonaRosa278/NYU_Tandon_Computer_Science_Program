#include <iostream>
#include <math.h>
using namespace std;

//a
int sumOfSquares(int arr[], int arrSize)
{
      if (arrSize <= 0)
      {
            return 0;
      }
      return (sumOfSquares(arr, arrSize - 1) + pow(arr[arrSize - 1], 2));
}
//b
bool isSorted(int arr[], int arrSize)
{
      if (arrSize == 1 || arrSize == 0)
            return true;
      if (arr[arrSize - 1] < arr[arrSize - 2])
            return false;
      return isSorted(arr, arrSize - 1);
}

int main()
{
      int arr[] = {2, -1, 3, 10};
      int sum = sumOfSquares(arr, 4);
      cout << "The sum is: " << sum << endl;
      int arr1[] = {98, 76, 44, 102};
      bool sorted = isSorted(arr1, 4);
      cout << "The array is sorted: " << boolalpha << sorted;
      return 0;
}