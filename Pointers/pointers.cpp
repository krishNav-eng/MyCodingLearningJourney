#include <iostream>
using namespace std;

int main() {
    // pointers = variable that stores the memory address of another variable
    // sometimes it's easier to work with memory addresses than the actual values
    // & = "address of" operator
    // * = "value at" operator or dereference operator

    int some_value = 42;
    int *pointer_to_value = &some_value; // pointer that holds the address of some_value
    cout << "Address: " << &pointer_to_value << endl;
    cout << "Value accessed using address value: " << *pointer_to_value << endl; // to access the value at the address we use the dereference operator *


    string some_string = "Hello, Pointers!";
    string *pointer_to_string = &some_string;
    cout << "Address: " << pointer_to_string << endl;
    cout << "Value accessed using address value: " << *pointer_to_string << endl;

    int prime_numbers[5] = {2, 3, 5, 7, 11};
    int *p_prime_numbers = prime_numbers;
    cout << prime_numbers << endl;
    cout << "We can get first element of the list using deference operator applied on the prime_numbers: " << *p_prime_numbers << endl;
    cout << "Address of first element of prime numbers: " << &prime_numbers << endl;

    return 0;
}