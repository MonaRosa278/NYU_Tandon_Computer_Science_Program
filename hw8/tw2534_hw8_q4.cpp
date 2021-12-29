#include <iostream>
using namespace std;

int recursiveCost(int *arr, int currentIndex, int size)
{
      //find the base cases
      if (currentIndex == size - 1)
            return 0;
      if (currentIndex == size - 2)
            return arr[currentIndex + 1];
      //compare elements
      return min(arr[currentIndex + 1] + recursiveCost(arr, currentIndex + 1,
                                                       size),
                 arr[currentIndex + 2] + recursiveCost(arr, currentIndex + 2,
                                                       size));
}
int main()
{
      int arr[] = {0, 3, 80, 6, 57, 10};
      int n = 6;
      int currentIndex = 0;

      cout << "The lowest cost for this game is " << recursiveCost(arr, currentIndex, n);
}