#include <iostream>
using namespace std;
//define the function to find the missing values
int *findMissing(int arr[], int n, int &resArrSize)
{
      int *temp = new int[resArrSize + 1];
      //declare a new array with 0s
      for (int i = 0; i < resArrSize + 1; i++)
            temp[i] = 0;
      for (int i = 0; i < resArrSize; i++)
            temp[arr[i]]++;

      int *result = new int[resArrSize + 1];
      int index = 0;
      //if the value in temp is 0 means that index does not appear in the old arr
      for (int i = 0; i < resArrSize + 1; i++)
            if (temp[i] == 0)
                  result[index++] = i;

      // update the resArrSize
      resArrSize = index;
      return result;
}

int main()
{
      //test the function
      int *arr = new int[10];
      arr[0] = 3;
      arr[1] = 1;
      arr[2] = 3;
      arr[3] = 0;
      arr[4] = 6;
      arr[5] = 4;
      int resArraySize = 6;
      int *result = findMissing(arr, 6, resArraySize);

      cout << "The missing values are: ";

      for (int i = 0; i < resArraySize; i++)
      {
            cout << result[i] << " ";
      }
      cout << endl
           << "The updated arrsize is: " << resArraySize;

      return 0;
}
