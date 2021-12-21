#include <iostream>
using namespace std;


// class members are private by default, whereas struct members are public by default.
class MyClass {
    private:
        int amount = 3000;    // class variable
    public:    // access specifier
        MyClass() {    // class constructor, with no return type
            cout << "Object created!" << endl;
        }
        void MyMethod() {   // class methods
            cout << "Hello world!" << endl;
        }
        const int getAmount() const {    // 'getter', const keyword prevent class method from modifying class variables 
            return amount;
        }
        void setAmount(int num) {    // 'setter'
            amount = num;
        }
};    // semicolon after class declaration! same goes with struct 

int main() {
    MyClass MyObject;
    MyObject.MyMethod();
    cout << "The amount is currently " << MyObject.getAmount() << endl;
    MyObject.setAmount(10000);
    cout << "The amount is currently " << MyObject.getAmount() << endl;
    return 0;
}