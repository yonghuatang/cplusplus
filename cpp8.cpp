#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    int y;
    cout << "Please enter a number x: ";
    cin >> x;
    cout << "Please enter a number y: ";
    cin >> y;
    if (x > y) {
        cout << x << " is greater than " << y;
    }
    else {
        cout << x << " is smaller than " << y;
    }
    return 0;
}