
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
     srand(time(0));
     int rand_int = (rand() % 100) + 1; // initiate the random number between 1~100
     int num_guess = 5;
     int guess;
     int range_start = 1;
     int range_end = 100;
     bool guessed = false;

     cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
     while (num_guess > 0)
     {
          cout << "Range: [" << range_start << ", " << range_end << "], Number of guesses left: " << num_guess << endl;
          cout << "Your guess: ";
          cin >> guess;

          if (guess == rand_int)
          {
               cout << "Congrats! You guessed my number in " << num_guess << endl;
               guessed = true;
               break;
          }

          else if (guess < rand_int)
          {
               cout << "Wrong! My number is bigger." << endl;
               range_start = guess + 1;

               if (guess >= range_start && guess <= range_end)
               {
                    range_start = guess + 1;
               }
          }

          else if (guess > rand_int)
          {
               cout << "Wrong! My number is smaller." << endl;
               if (guess >= range_start && guess <= range_end)
               {

                    range_end = guess - 1;
               }
          }
          num_guess--;
     }

     if (!guessed)
     {
          cout << "Out of  guess! My number is " << rand_int << endl;
     }

     return 0;
}