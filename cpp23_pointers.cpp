// pointers 
// Created by Yonghua :)

# include <iostream>
// # include <string>
using namespace std;


int main() {
    string fruit = "Apple";
    string* ptr = &fruit;

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
