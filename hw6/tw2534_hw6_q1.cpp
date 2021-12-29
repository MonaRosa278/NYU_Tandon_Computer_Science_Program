#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

//define the minINArray function
int minInArray(int arr[], int arrSize)
{
      int min_num;
      min_num = arr[0];

      for (int i = 0; i < arrSize; ++i)
      {
            if (arr[i] < min_num)
                  min_num = arr[i];
      }
      return min_num;
}

int main()
{
      //declaring variables
      int input_min, input_num;
      int arrSize = 20;
      int arr[arrSize], i;

      //taking elements of the array as input from the user
      cout << "Please enter 20 integers seperated by a space: ";
      for (int j = 0; j < arrSize; ++j)
      {
            cin >> input_num;
            arr[j] = input_num;
      }
      input_min = minInArray(arr, arrSize);
      cout << "\nThe minimum value is " << input_min << ", and it is located in the following indices:";
      for (int k = 0; k < arrSize; ++k)
      {
            if (arr[k] == input_min)
                  cout << " " << k;
      }
}
