#include <iostream>
using namespace std;

class Student {
    public:
        // Attributes
        string First_Name;
        string Last_Name;
        int Age;
        string All;
        // Constructor (same as __init__ method in Python)
        Student(string first_name, string last_name, int age) {  
            First_Name = first_name;
            Last_Name = last_name;
            Age = age;
            All = first_name + ' ' + last_name + ' ' + to_string(age); // int => string
        }
};

int main() {
    Student Student_001("John", "Doe", 18);
    Student Student_002("Ali", "Baba", 35);

    cout << "Welcome! " + Student_001.First_Name + ' ' + Student_001.Last_Name + "\n";
    cout << "Hello! " + Student_002.All;
    return 0;
}