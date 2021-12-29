#include <iostream>
using namespace std;

//define the function to reorder the array
void oddKeepEvensFlip(int arr[], int arrSize)
{
      //declare a new array
      int new_arr[arrSize], idx = 0;
      //for odd numbers we add them  to the new array from left to right to keep their original order
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] % 2 == 1)
                  new_arr[idx++] = arr[i];
      }
      //for even numbers we add them to the new array from right to left to reverse their order
      for (int i = arrSize - 1; i >= 0; i--)
      {
            if (arr[i] % 2 == 0)
                  new_arr[idx++] = arr[i];
      }
      for (int i = 0; i < arrSize; i++)
      {
            arr[i] = new_arr[i];
      }
}

int main()
{
      //test the function
      int res[6];
      int arr[] = {5, 2, 11, 7, 6, 4};
      oddKeepEvensFlip(arr, 6);
      for (int i = 0; i < 6; i++)
      {
            cout << arr[i] << " , ";
      }
      return 0;
}
