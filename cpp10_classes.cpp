#include <iostream>
using namespace std;

class MyClass {
    public:
        void MyMethod() {
            cout << "Hello world!";
        } 
};

int main() {
    MyClass MyObject;
    MyObject.MyMethod();
    return 0;
}