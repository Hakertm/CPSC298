/// @file leibnitz_pi
/// @brief Gets user inputs for n(number of iterations) and calculates PI using leibnitz formula and outputs it.
/// @author Erik Fryanov

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    int n;
    double pi = 0.0;

    cout << "Enter a non-negative integer: " << endl;
    cin >> n;
    
    // PI summation
    for (int k = 0; k <= n; ++k) {
        pi += (pow(-1.0, k)) / ((2.0 * k ) + 1.0);
    }

    // Output approximate and actual value of pi
    cout << setprecision(16)<< "PI (approx): " << 4.0 * pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;

    // Show if PI could have been represented exactly
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: "
            << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: "
            << nextafter(3.141592653589793, 3.14) << endl;

    return 0;
}
