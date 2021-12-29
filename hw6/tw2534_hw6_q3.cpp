#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

//define the reverse array funciton
void reverseArray(int arr[], int arrSize)
{
      int temp;
      for (int i = 0; i < arrSize / 2; ++i)
      {
            temp = arr[i];
            arr[i] = arr[arrSize - i - 1];
            arr[arrSize - 1 - i] = temp;
      }
}
//define remove odd numbers funciton
void removeOdd(int arr[], int &arrSize)
{
      int count = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] % 2 != 0)
            {
                  int j = i + 1;
                  for (int k = i; k < arrSize; k++)
                  {
                        arr[k] = arr[j];
                        j++;
                  }
                  count++;
                  i--;
            }
      }
      arrSize = arrSize - count;
}
//define reorder the odd and even numbers function
void swap(int a, int b)
{
      int temp = a;
      a = b;
      b = temp;
}
void splitParity(int arr[], int arrSize)
{
      int i = 0, j = arrSize - 1;
      while (i < j)
      {
            while (arr[i] % 2 == 1 && i < j)
            {
                  i++;
            }
            while (arr[j] % 2 == 0 && i < j)
            {
                  j--;
            }
            if (i < j)
            {
                  swap(arr[i], arr[j]);
                  i++;
                  j--;
            }
      }
}
//print function
void printArray(int arr[], int arrSize)
{
      int i;
      for (i = 0; i < arrSize; i++)
      {
            cout << arr[i] << ' ';
      }
      cout << endl;
}

int main()
{
      int arr1[10] = {9, 2, 14, 12, -3};
      int arr1Size = 5;
      int arr2[10] = {21, 12, 6, 7, 14};
      int arr2Size = 5;
      int arr3[10] = {3, 6, 4, 1, 12};
      int arr3Size = 5;
      reverseArray(arr1, arr1Size);
      printArray(arr1, arr1Size);
      removeOdd(arr2, arr2Size);
      printArray(arr2, arr2Size);
      splitParity(arr3, arr3Size);
      printArray(arr3, arr3Size);
      return 0;
}
