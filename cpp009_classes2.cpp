/* Another example for C++ classes. Created by James Tang 21 December 2021 11:22 PM */
#include <iostream>
using namespace std;

class Student {
    private:
        string firstName;
        string lastName;
        int age;
        string all;

    public:
        Student(string foo, string bar, int baz) {  
            firstName = foo;
            lastName = bar;
            age = baz;
            all = firstName + " " + lastName + ", " + std::to_string(age);  // int => string
        }

        string getName() const {
            return firstName + " " + lastName;
        }

        string getAll() const {
            return all;
        }

        // Class insertion operator '<<' overloading
        friend ostream& operator<<(ostream& os, const Student& stu) {
            os << stu.all;
            return os;
        }
};

int main() {
    Student s1("John", "Doe", 18);
    Student s2("Ali", "Baba", 35);
    cout << "Welcome! " << s1.getName() << endl;
    cout << "Hello! " << s2.getAll() << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}