#include <iostream>
using namespace std;


class myClass {
    private:
        int x, y, z;
    public:
        // member initialisation list, constructor overloading
        myClass() : x{0}, y{0}, z{0}
        {
            cout << "An object is created! No argument passed!" << endl;
        }
        myClass(int a, int b, int c) : x{a}, y{b}, z{c}
        {
            cout << "An object is created! Arguments passed!" << endl;
        }
        void printValue() const {
            printf("Values: x=%d, y=%d, z=%d \n", x, y, z);
        }
};

/*
Member initialisation is not assignment!

==> This is class member assignment
myClass::myClass() {
    x = 0;
    y = 0;
    z = 0;
}

==> This is member initialisation
myClass::myClass() : x{0}, y{0}, z{0] {} 
*/

int main() {
    myClass m1;
    myClass m2(7, 8, 9);
    m1.printValue();
    m2.printValue();
    return 0;
}