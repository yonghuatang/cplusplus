# include <iostream>
using namespace std;

// A struct (short for structure) allows us to group variables of mixed data types together into a single unit.

struct Employee {
    int age;
    string first_name;
    string last_name;
    float salary;
}; // semicolon!!

Employee joe{21, "joe", "mozart", 30000};

int main() {
    cout << joe.age;
    return 0;
}