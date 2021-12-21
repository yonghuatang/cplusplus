#include <iostream>
using namespace std;

// Create a function
void myFunction() {
    cout << "I just got executed!" << endl;
}

int addNumbers(int i, int j){
    return i + j;
}

void setNumber(int i, int j){
    i = j;
}

int main() {
    myFunction(); // call the function
    cout << AddNumbers(7, 8) << endl;
    int a = 7;
    int b = 8;
    setNumber(a, b);
    return 0;
}
