#include <iostream>
using namespace std;

//define a boolean function to compare two strings
bool isAnagram(string s1, string s2)
{
      //declare an array to count each letters(initiate with 0s)
      int freqArray[26] = {0};
      for (int i = 0; i < s1.length(); ++i)
      {

            if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                  freqArray[s1[i] - 'A']++;
            }
            if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                  freqArray[s1[i] - 'a']++;
            }
      }
      //use the count of letters appeared in string1 to minus the count in string2, if theres some left,then they are not anagrams.
      for (int i = 0; i < s2.length(); ++i)
      {
            if (s2[i] >= 'A' && s2[i] <= 'Z')
            {
                  freqArray[s2[i] - 'A']--;
            }
            if (s2[i] >= 'a' && s2[i] <= 'z')
            {
                  freqArray[s2[i] - 'a']--;
            }
      }
      //check if there is letter left, 0 means anagrams not 0 means not anagrams
      for (int i = 0; i < 26; ++i)
      {
            if (freqArray[i] != 0)
                  return false;
      }
      return true;
}

int main()
{
      //get users input and call the function
      string s1, s2;
      cout << "Please enter your first string: ";
      getline(cin, s1);
      cout << "Please enter your second string: ";
      getline(cin, s2);
      cout << "results: ";
      if (isAnagram(s1, s2))
            cout
                << endl
                << '"' << s1 << '"' << " is an Anagrams of " << '"' << s2 << '"';
      else
            cout << endl
                 << '"' << s1 << '"' << " is not an Anagrams of " << '"' << s2 << '"';

      return 0;
}
