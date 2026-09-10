#include <iostream>

using namespace std;

int main()
{
    int statusReg = 100;

    int controlReg = 200;

    int dataReg = 300;


    // const int*

    const int* ptr1 = &statusReg;

    cout << "const int* : "
         << *ptr1 << endl;

    ptr1 = &dataReg;


    // int* const

    int* const ptr2 = &controlReg;

    *ptr2 = 500;

    cout << "int* const : "
         << *ptr2 << endl;


    // const int* const

    const int* const ptr3 = &statusReg;

    cout << "const int* const : "
         << *ptr3 << endl;


    return 0;
}