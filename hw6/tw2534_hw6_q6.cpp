#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
      string text;
      cout << "Enter a line of text: ";
      getline(cin, text);
      cout << "Your output is:" << endl;

      // break sentence into single words
      stringstream s(text);
      string word;

      //check each word if its digit or string
      while (s >> word)
      {
            int flag = 0;
            for (int i = 0; i < word.size(); i++)
            {
                  if (!isdigit(word[i]))
                        flag = 1;
            }
            if (flag == 1)
                  cout << word << " ";
            else
            {
                  for (int j = 0; j < word.size(); j++)
                  {
                        word[j] = 'x';
                  }
                  cout << word << " ";
            }
      }
      return 0;
}