/// @file hello_cin
/// @brief Asks user to input a word and outputs it
/// @author Erik Fryanov

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}
