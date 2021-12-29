
/*
 1. get users input on prices, club card and tax rate
 2. compare the prices and get the total price before discount
 3. apply half price promotion
 4. apply additional discount (if applicable)
 */
#include <iostream>

using namespace std;

int main()
{

    int price_of_first_item, price_of_second_item, base_price;
    char input;
    double tax_rate, prices_with_promotion, price_after_discount, total_price;

    // get all the inputs from users and check if they are valid
    cout << "Enter price of first item: ";
    cin >> price_of_first_item;

    cout << "Enter price of second item: ";
    cin >> price_of_second_item;

    cout << "Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)";
    cin >> input;
    cout << "Enter tax rate: ";
    cin >> tax_rate;

    base_price = price_of_first_item + price_of_second_item;
    cout << "base price: " << base_price << endl;

    //decide which item is applicable for the half price promotion
    if (price_of_first_item > price_of_second_item)
    {
        prices_with_promotion = price_of_first_item + price_of_second_item / 2;
    }
    else
    {
        prices_with_promotion = price_of_second_item + price_of_first_item / 2;
    }

    //see if the user has a club card
    //we use else if not else just in case user put some character neither y or n
    if (input == 'Y' || input == 'y')
    {
        price_after_discount = prices_with_promotion * 0.9;
    }
    else if (input == 'N' || input == 'n')
    {
        price_after_discount = prices_with_promotion;
    }
    cout << "Price after discounts: " << price_after_discount << endl;
    //add the tax
    total_price = price_after_discount * (1 + tax_rate / 100);
    cout << "Total price: " << total_price << endl;

    return 0;
}