// References and memory address

# include <iostream>
# include <string>
using namespace std;


int main() {
    string food = "Pizza";
    string &meal = food;  // reference '&' (aka alias)
    cout << food << endl;
    cout << meal << endl;
    cout << &food << endl;  // memory address of food
    cout << &meal << endl;  // same memory address as food
    return 0;
}