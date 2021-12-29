#include <iostream>
using namespace std;

//define the function which convert the sentence into array
string *createWordsArray(string sentence, int &ArrWords)
{
      for (int i = 0; i < sentence.length(); i++)
      {
            if (sentence[i] == ' ')
                  ArrWords++;
      }
      ArrWords++;

      // Creating a dynamic array
      string *strWords = new string[ArrWords];
      int counter = 0;

      for (int i = 0; i < sentence.length(); ++i)
      {
            if (sentence[i] == ' ')
            {
                  counter++;
                  i++;
            }
            strWords[counter] += sentence[i];
      }
      return strWords;
}
int main()
{
      // Declaring variables and get users input
      string sentence;
      int ArrWords = 0;
      string *strWords;

      cout << "Enter Sentence: ";
      getline(cin, sentence);

      strWords = createWordsArray(sentence, ArrWords);
      cout << "The words in wordsArray: " << endl;
      for (int i = 0; i < ArrWords; i++)
      {
            cout << strWords[i] << endl;
      }
      cout << "The updated arrsize is: " << ArrWords;

      return 0;
}
