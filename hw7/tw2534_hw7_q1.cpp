#include <iostream>
using namespace std;

int main()
{
      //get users input
      string text;
      cout << "Enter a line of text: " << endl;
      getline(cin, text);

      //declare an array to count each letter(26 possible letters)
      int count[26] = {0};
      int wordCount = 0;
      for (int i = 0; i < text.size(); ++i)
      {
            if (((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ' '))
                  wordCount++;
            if (text[i] >= 'a' && text[i] <= 'z')
                  count[text[i] - 'a']++;
            if (text[i] >= 'A' && text[i] <= 'Z')
                  count[text[i] - 'A']++;
      }
      char x = text[text.size() - 1];
      if (x != '.' && x != 'z' && x != ' ')
            wordCount++;
      //print out the results
      cout << wordCount << '\t' << "words" << endl;
      for (int i = 0; i < 26; i++)
      {
            if (count[i] > 0)
                  cout << count[i] << '\t' << (char)('a' + i) << endl;
      }
}