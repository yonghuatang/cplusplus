#include <iostream>
using namespace std;


// class members are private by default, whereas struct members are public by default.
class MyClass {
    private:
        int amount = 3000;    // class variable (a.k.a attribute) declared as private, inaccessible outside class
    public:    // access specifier
        MyClass() {    // class constructor, with no return type
            cout << "Object created!" << endl;
        }
        void myMethod() {   // class methods
            cout << "Hello world!" << endl;
        }
        int getAmount() const {
        /* 'getter'; 'const' keyword prevent class method from modifying
           class attributes, but can be bypassed by 'mutable' keyword*/
            return amount;
        }
        void setAmount(int num) {    // 'setter'
            amount = num;
        }
        ~MyClass() {    // class destructor
            cout << "Object destroyed!" << endl;
        }
};    // semicolon after class declaration! same goes with struct 


/*
Class method definition can also be done outside the class, for example myMethod()

void MyClass::myMethod() {cout << "Hello world!" << endl;}
*/


int main() {
    MyClass MyObject;
    MyObject.myMethod();
    cout << "The amount is currently " << MyObject.getAmount() << endl;
    MyObject.setAmount(10000);
    cout << "The amount is currently " << MyObject.getAmount() << endl;
    return 0;
}