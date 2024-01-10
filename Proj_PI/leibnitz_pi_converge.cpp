/// @file leibnitz_pi_converge
/// @brief Outputs PI values up to 2^20th n value.
/// @author Erik Fryanov

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    double pi;
    
    // PI summation
    for (int n = 2; n <= 1048576; n *= 2) {
        pi = 0.0;
        for (int k = 0; k <= n; ++k) {
            pi += (pow(-1.0, k)) / ((2.0 * k ) + 1.0);
        }
        // Output PI and n value
        cout << setprecision(16) << "PI: " << 4.0 * pi << setw(7) << "; n: " << n << endl; 
    }

    return 0;
}