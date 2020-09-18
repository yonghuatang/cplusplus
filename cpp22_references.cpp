// references and memory address

# include <iostream>
# include <string>
using namespace std;

int main() {
    string food = "Pizza";
    string &meal = food; // reference '&'
    cout << food << endl;
    cout << meal << endl;
    cout << &food << endl; // memory address
    cout << &meal << endl; 
    return 0;
}