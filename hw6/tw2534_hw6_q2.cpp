#include <iostream>
using namespace std;

//define the function
bool isPalindrome(string str)
{
      int i, length;
      bool flag = true;
      length = str.length(); //the length of the word
      for (i = 0; i < length; i++)
      {
            if (str[i] != str[length - i - 1])
            {
                  flag = false;
                  break;
            }
      }
      return flag;
}

int main()
{
      string word;
      cout << "Please enter a word: ";
      cin >> word;
      if (isPalindrome(word))

            cout << word << " is a palidrome";

      else

            cout << word << " is not a palidrome";
}
