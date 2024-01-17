// SomePointers.cpp Project
// Code is incomplete but will run
//

#include <iostream>
using namespace std;

int main() {
    const int ARRAY_SIZE = 10;
    const int LAST_ARRAY_ELEM_INDEX = 9;
   
    char* p_aChars = new char[ARRAY_SIZE];
    int* p_aIntegers = new int[ARRAY_SIZE];

    cout << "Pointer Project\n";


    //Example of using #if 0 to comment out code:
#if 0
    BAD_CODE - BUT - IT - IS - COMMENTED - OUT THANKS TO if 0
#endif

#if 0
    // Initialize character array
    p_aChars[0] = 'A';
    p_aChars[1] = 'B';
    p_aChars[2] = 'C';
    p_aChars[3] = 'C';
    p_aChars[4] = 'E';
    p_aChars[5] = 'F';
    p_aChars[6] = 'G';
    p_aChars[7] = 'G';
    p_aChars[8] = 'I';
    p_aChars[9] = 'J';
    
    // Initialize character array
    p_aIntegers[0] = 100;
    p_aIntegers[1] = 101;
    p_aIntegers[2] = 102;
    p_aIntegers[3] = 103;
    p_aIntegers[4] = 104;
    p_aIntegers[5] = 105;
    p_aIntegers[6] = 106;
    p_aIntegers[7] = 107;
    p_aIntegers[8] = 108;
    p_aIntegers[9] = 109;

#endif


    // ////////////////////////////////////////////////////////////////////////////
    // Character Pointer Code
    // ////////////////////////////////////////////////////////////////////////////

    char* p_c = p_aChars;  // Same as p_c = &(p_aChars[0]);
    char c = 'A';
    
    //Populates array with characters
    while(p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {
        *p_c = c;
        ++c;
        ++p_c;
    }

    // Display Character Array
    cout << "Char Array" << endl;
    cout << "Address of last element &(p_aChars[LAST_ARRAY_ELEM_INDEX]): " 
            << static_cast<void*>(&(p_aChars[LAST_ARRAY_ELEM_INDEX])) << endl;

    p_c = p_aChars;

    while (p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {

        cout << "p_c: " << static_cast<void*>(p_c) << ":  *p_c: " << *p_c << endl;

        p_c++;  // Increment the pointer (to point to next array element)
    }


    // ////////////////////////////////////////////////////////////////////////////
    // Integer Pointer Code
    // ////////////////////////////////////////////////////////////////////////////

    int* p_i = p_aIntegers;  // Same as p_i = &(p_aOrdinals[0]);
    int n = 100;

    //Populate integer array
    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {
        *p_i = n;
        ++n;
        ++p_i;
    }

    // Display Integer Array
    cout << "Integer Array" << endl;
    cout << "Address of last element: &(p_aIntegers[LAST_ARRAY_ELEM_INDEX]): " << &(p_aIntegers[LAST_ARRAY_ELEM_INDEX]) << endl;

    p_i = p_aIntegers;

    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {

        cout << "p_i: " << p_i << ":  *p_i: " << *p_i << endl;

        p_i++;  // Increment the pointer (to point to next array element)
    }

    delete[] p_aChars;
    delete[] p_aIntegers;
    delete p_c;
    delete p_i;
    return 0;
   
}

