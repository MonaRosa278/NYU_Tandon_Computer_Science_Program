

/*get the users inputs
 *flow control for numbers of solutions*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{

    double a, b, c;
    //get all the user input
    cout << "Please enter value of a:";
    cin >> a;
    cout << "Please enter value of b:";
    cin >> b;
    cout << "Please enter value of c:";
    cin >> c;

    //The number of solutions depends on the values of a,b,c
    double discr = pow(b, 2) - 4 * a * c;
    //case 1
    if (a == 0 && b == 0 && c == 0)
    {

        cout << "Infinite number of solutions" << endl;
    }
    //case 2
    else if (a == 0 && b == 0 && c != 0)
    {

        cout << "No solution" << endl;
    }
    //case 3
    else if (a != 0 && b == 0 && c != 0)
    {

        cout << "No real solution" << endl;
    }
    //case 4
    else if (discr == 0)
    {

        double x = -b / (2 * a);
        printf("This equation has a single real solution x=%.1f", x);
    }
    //case 5
    else
    {

        if (discr < 0)
        {

            discr = discr * -1;
            discr = sqrt(discr);
            double real = -b / 2 * a;
            double imaginary = discr / 2 * a;
            printf("This equation has two real and imaginary solutions x=%.1f+%.1fi and x=%.1f-%.1fi", real, imaginary,
                   real, imaginary);
        }
        //case 6
        else
        {

            discr = sqrt(discr);
            double x1, x2;
            x1 = (-1 * b + discr) / 2 * a;
            x2 = (-1 * b - discr) / 2 * a;
            printf("This equation has two real solutions x=%.1f and x=%.1f", x1, x2);
        }
    }
    cout << endl;

    return 0;
}