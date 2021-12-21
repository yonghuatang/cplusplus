#include <iostream>
using namespace std;

// Create a function
void myFunction() {  // return type void
    cout << "I just got executed!" << endl;
}

int addNumbers(int i, int j){
    return i + j;
}

void increment(int& i){  // pass by reference
    i++;
}

int main() {
    myFunction(); // call the function
    cout << addNumbers(7, 8) << endl;
    int a = 7;
    increment(a);
    cout << "a = " << a << endl;
    return 0;
}
