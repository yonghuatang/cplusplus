# include <iostream>
using namespace std;

class MyClass {
    public:
        MyClass() {   // Constructor
            cout << "Object created!" << endl;
        }
        ~MyClass() {   // Destructor
            cout << "Object destroyed!" << endl;
        }
};

int main() {
    MyClass myObj;
    return 0;
}