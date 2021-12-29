#include <iostream>
using namespace std;

//define the first function
int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{
      int posSize = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posSize++;
            }
      }

      int *posArray = new int[posSize];

      int index = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posArray[index] = arr[i];
                  index++;
            }
      }
      outPosArrSize = posSize;
      return posArray;
}

//define the second fucntion
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{
      int posSize = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posSize++;
            }
      }

      int *posArray = new int[posSize];

      int index = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posArray[index] = arr[i];
                  index++;
            }
      }
      *outPosArrSizePtr = posSize;
      return posArray;
}
//define the third function
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{
      int posSize = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posSize++;
            }
      }

      outPosArr = new int[posSize];

      int index = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  outPosArr[index] = arr[i];
                  index++;
            }
      }
      outPosArrSize = posSize;
}
//define the fourth function
void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr)
{
      int posSize = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  posSize++;
            }
      }

      *outPosArrPtr = new int[posSize];

      int index = 0;
      for (int i = 0; i < arrSize; i++)
      {
            if (arr[i] > 0)
            {
                  (*outPosArrPtr)[index] = arr[i];
                  index++;
            }
      }
      *outPosArrSizePtr = posSize;
}

int main()
{
      int arr[] = {3, -1, -3, 0, 6, 4};
      int size = 6;

      int newSize;
      cout << "getPosNums1: " << endl;
      int *posArray = getPosNums1(arr, size, newSize);
      for (int i = 0; i < newSize; i++)
      {
            cout << posArray[i] << " ";
      }

      cout << endl
           << "getPosNums2: " << endl;
      int *newPosArray = getPosNums2(arr, size, &newSize);
      for (int i = 0; i < newSize; i++)
      {
            cout << newPosArray[i] << " ";
      }

      cout << endl
           << "getPosNums3: " << endl;
      int *posArray3;
      getPosNums3(arr, size, posArray3, newSize);
      for (int i = 0; i < newSize; i++)
      {
            cout << posArray3[i] << " ";
      }

      cout << endl
           << "getPosNums4: " << endl;
      int *posArray4;
      getPosNums4(arr, size, &posArray4, &newSize);
      for (int i = 0; i < newSize; i++)
      {
            cout << posArray4[i] << " ";
      }

      return 0;
}