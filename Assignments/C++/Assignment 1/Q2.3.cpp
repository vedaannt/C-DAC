#include <iostream>

using namespace std;

int main()
{
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;


    // const int*
    // Value cannot be changed
    // Pointer can be changed

    const int* regPtr1 = &statusReg;

    cout << "Status Register : "
         << *regPtr1 << endl;
    // ERROR: Cannot change value
    regPtr1 = &dataReg;
    // Allowed: pointer can point somewhere else
    // int* const
    // Value can be changed
    // Pointer cannot be changed

    int* const regPtr2 = &controlReg;

    *regPtr2 = 20;

    cout << "Control Register : "
         << *regPtr2 << endl;
    // ERROR: Pointer cannot be changed
    // const int* const
    // Value cannot be changed
    // Pointer cannot be changed

    const int* const regPtr3 = &statusReg;

    cout << "Status Register : "
         << *regPtr3 << endl;
    return 0;
}