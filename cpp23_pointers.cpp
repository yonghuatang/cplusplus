// pointers 
// Created by Yonghua :)

# include <iostream>
# include <string>
using namespace std;

int main() {
    string fruit = "Apple";
    string* ptr = &fruit;
    cout << fruit << "\n";
    cout << &fruit << "\n";
    cout << ptr << "\n"; // Reference: Output the memory address of fruit with the pointer
    cout << *ptr << "\n"; // Dereference: Output the value of fruit with the pointer
    return 0;
}
