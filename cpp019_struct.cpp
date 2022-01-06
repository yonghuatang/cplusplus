# include <iostream>
using namespace std;

// A struct (short for structure) allows us to group variables of mixed data types together into a single unit.
// unlike class, struct members are public by default, and normally doesn't have methods (or functions).

struct Employee {
    int age;
    string first_name;
    string last_name;
    float salary;
};    // semicolon!!


int main() {
    Employee joe{21, "joe", "mozart", 30000};
    cout << joe.age;
    joe.age = 22;
    cout << joe.age;
    return 0;
}
