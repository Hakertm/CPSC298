/// @file authenticator
/// @brief Gets 3 different characters from user inputs and checks if it matchs the authentication code.
/// @author Erik Fryanov

#include <iostream>
#include <string>
using namespace std;

int main () {
    //Initialize Variables
    const char AUTH_CODE_CHAR1 = 'E';
    const char AUTH_CODE_CHAR2 = 'C';
    const char AUTH_CODE_CHAR3 = 'A';
    const int AUTH_VALID_CHECKSUM = 5;
    char userChar1;
    char userChar2;
    char userChar3;
    string authCode;
    string messageCode;
    int messageChecksum = 0;
    bool match = true;

    //Get user characters for message code.
    //First character
    cout << "Enter the first character of the message code(uppercase): " << endl;
    cin >> userChar1;
    cout << endl;

    //Second
    cout << "Enter the second character of the message code(uppercase): " << endl;
    cin >> userChar2;
    cout << endl;

    //Third
    cout << "Enter the third character of the message code(uppercase): " << endl;
    cin >> userChar3;
    cout << endl;

    //-----------------------------------------------------------------------------------------------

    //Concatenate characters to string
    authCode += AUTH_CODE_CHAR1;
    authCode += AUTH_CODE_CHAR2;
    authCode += AUTH_CODE_CHAR3;

    messageCode += userChar1;
    messageCode += userChar2;
    messageCode += userChar3;

    //Output strings
    cout << "Authenticator Code: " << authCode << endl;
    cout << "Message Code: " << messageCode << endl << endl;


    //Iterate through message code and check if each character matches
    for (int i = 0; i < authCode.size(); ++i) {
        if (messageCode.at(i) != authCode.at(i)) {
            match = false;
            break;
        }
    }

    //Prints if message is authentic or not.
    if (match) {
        cout << "Message is authentic." << endl;
    }
    else {
        cout << "Message is invalid." << endl;
    }

    //Compare strings directly to double check authenticity
    if (messageCode == authCode) {
        cout << "Concurrence: message is authentic." << endl << endl;
    }
    else {
        cout << "Concurrence: message is invalid." << endl << endl;
    }

    //-----------------------------------------------------------------------------------------------

    //Checksum check
    messageChecksum = (int(userChar1) + int(userChar2) + int(userChar3)) % 7;

    if (messageChecksum == AUTH_VALID_CHECKSUM) {
        cout << "Message Code Checksum is valid: " << AUTH_VALID_CHECKSUM << endl;
    }
    else {
        cout << "Message Code Checksum is invalid: " << messageChecksum << "; ";
        cout << "Expected: " << AUTH_VALID_CHECKSUM << endl;
    }

    //Display ASCII values of each character and their sum.
    cout << "ASCII Values of Message Code Characters: ";
    cout << int(userChar1) << ", " << int(userChar2) << ", " << int(userChar3) << endl;
    
    //Sum
    cout << "Sum of ASCII Values for Message Code Characters: ";
    cout << int(userChar1) + int(userChar2) + int(userChar3) << endl;

    //-----------------------------------------------------------------------------------------------

    //Report which pairs of characters don't match
    //Pair 1
    if(userChar1 != AUTH_CODE_CHAR1){
        cout << "First character does not match: Message: " << userChar1 << "; ";
        cout << "Authenticator: " << AUTH_CODE_CHAR1 << endl;
    }

    //Pair 2
    if(userChar2 != AUTH_CODE_CHAR2){
        cout << "Second character does not match: Message: " << userChar2 << "; ";
        cout << "Authenticator: " << AUTH_CODE_CHAR2 << endl;
    }

    //Pair 3
    if(userChar3 != AUTH_CODE_CHAR3){
        cout << "Third character does not match: Message: " << userChar3 << "; ";
        cout << "Authenticator: " << AUTH_CODE_CHAR3 << endl;
    }

    //-----------------------------------------------------------------------------------------------

    //Compare if message code is lexicographically greater or less than auth code
    //Greater than
    if (messageCode > authCode) {
        cout << "Message code (" << messageCode << ") is lexicographically greater than ";
        cout << "Authenticator code (" << authCode << ")" << endl;
    }

    //Less than
    if (messageCode < authCode) {
        cout << "Message code (" << messageCode << ") is lexicographically less than ";
        cout << "Authenticator code (" << authCode << ")" << endl;
    }


    return 0;

}