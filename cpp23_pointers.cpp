# include <iostream>
using namespace std;

int main() {
    string fruit = "Apple";
    string* ptr = &fruit;
    const string* ptr1 = &fruit;        // Pointer to const string
    string const* ptr2 = &fruit;        // Equivalent to ptr1
    string* const ptr3 = &fruit;        // Const pointer to string
    const string* const ptr4 = &fruit;  // Const pointer to const string

    // Print "Apple"
    cout << fruit << endl;

    // Print the memory address of fruit
    cout << &fruit << endl;

    // Reference: Return the memory address of fruit through the pointer variable
    cout << ptr << endl;
    
    // Dereference: Return the value of fruit by dereferencing the pointer variable
    cout << *ptr << endl;
    
    return 0;
}
