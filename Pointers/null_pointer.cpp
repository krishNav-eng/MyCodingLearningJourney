#include <iostream>
using namespace std;


int main() {
    int *pointer = nullptr;
    int x = 123;

    // pointer = &x; // pointer now points to x

    if(pointer == nullptr) {
        cout << "pointer not been assigned any address." << endl;
    } else {
        cout << "address was assigned" << endl;
        cout << "The value at the address of pointer: " << *pointer << endl;
    }

    *pointer;

}