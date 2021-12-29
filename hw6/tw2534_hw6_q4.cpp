#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//define function to get 10 randon digits between 1-3
void assign_random_numbers(int nums[])
{
      for (int i = 0; i <= 9; i++)
      {
            nums[i] = rand() % 3 + 1;
      }
}
//define print function to print out all the random numbers
void print_random_numbers(int nums[])
{
      cout << "PIN:   0 1 2 3 4 5 6 7 8 9\n";
      cout << "NUM:   ";
      for (int i = 0; i <= 9; i++)
            cout << nums[i] << " ";
      cout << endl;
}
//define function to get the encypted pin
int get_encrypted_pin(int nums[], int pin)
{
      int encrypted_pin = 0;
      int right_digit, encrypted_digit;
      int base = 1;
      while (pin != 0)
      {
            right_digit = pin % 10;
            encrypted_digit = nums[right_digit];
            encrypted_pin = encrypted_pin + encrypted_digit * base;
            base = base * 10;
            pin = pin / 10;
      }
      return encrypted_pin;
}

int main()
{
      srand(time(0));
      int pin = 12345;

      int nums[10];
      assign_random_numbers(nums);

      int user_input;
      cout << "Please enter your PIN according to the following mapping:\n";
      print_random_numbers(nums);
      cin >> user_input;
      // see if the input pin is equal to the encrypted pin
      int encrypted_pin = get_encrypted_pin(nums, pin);
      if (user_input == encrypted_pin)
            cout << "Your PIN is correct\n";
      else
            cout << "Your PIN is not correct\n";

      return 0;
}