# include <iostream>
using namespace std;


int main() {
    int foo[5] = {1, 2, 3, 4, 5};
    cout << "Before change: " << endl;
    for (const auto i : foo) {
        cout << i << endl;
    }
    for (auto& i : foo) {    // pass by reference
        i++;
    }
    cout << "After change: " << endl;
    for (const auto i : foo) {
        cout << i << endl;
    }
    return 0;
}