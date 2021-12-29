#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
      // Declaring variables
      string line;
      string firstName, middleName, lastName;

      //Getting the input entered by the user
      cout << "Please enter your name(first middle last): ";
      getline(cin, line);

      // parsing the string based on the space
      int index = line.find(" ");
      firstName = line.substr(0, index);
      line = line.substr(index + 1, line.length() - 1);
      index = line.find(" ");
      middleName = line.substr(0, index);
      lastName = line.substr(index + 1, line.length() - 1);
      if (middleName.at(middleName.length() - 1) == '.')
      {
            middleName = middleName.at(0);
      }
      else
      {
            middleName = middleName.at(0);
      }

      cout << lastName << ", " << firstName << " " << middleName << "." << endl;

      return 0;
}
