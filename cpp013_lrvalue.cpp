/* Value categories: lvalue and rvalue ::: James Tang 02 Jan 2022 */

#include <iostream>
using namespace std;


int i = 10;  // variable declaration and assignment; i is lvalue, 10 is rvalue
// 10 = i doesn't work!
int a = i;  // both a and i are lvalues!

int myFunc() {
    return 20;  // returns an rvalue
}

int& myFunc1() {
    static int value = 20;
    return value;  // returns a ref to an lvalue
}

// ========================

// accept int& (lvalue reference) as argument
// We can accept 'const int&' if we also want to pass rvalue, but it is not
// valid for this case because we are incrementing the reference variable
// so it must be modifiable.
void increment_A(int& i) {
    i++;
}

// accept int&& (rvalue reference) as argument
void increment_B(int&& i) {
    i++;
}

int main() {
    int num = 34;
    
    increment_A(num);  // pass lvalue as argument, it works
    // increment_A(45);  // pass rvalue, doesn't work!

    // increment_B(num);  // pass lvalue as argument, doesn't work!
    increment_B(45);  // pass rvalue, it works

    return 0;
}
