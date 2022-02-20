#include <bits/stdc++.h>
using namespace std;

double pi = 3.14159265359, e = 2.71828182846, feigenbaum = 4.66920160910;
double values[] = {1, 1.2, 1.23, 1.234, 1.2345, 1.23456};

int main() {
    // Print formatting floating point numbers
    cout << "=== Floating point numbers ===" << endl;
    // Default
    cout << "Default:  " << pi << "  " << e << "  " << feigenbaum << endl;
    // Fixed decimal places
    cout << setprecision(8) << std::fixed << "std::fixed:  " << pi << "  " << e << "  " << feigenbaum << endl;
    // Scientific notation
    cout << setprecision(3) << std::scientific << "std::scientific:  " << pi << "  " << e << "  " << feigenbaum << endl;
    // Back to default
    cout << setprecision(-1) << std::defaultfloat << "Default:  " << pi << "  " << e << "  " << feigenbaum << endl;

    // Output width
    cout << "=== Output width ===" << endl;
    for (double i : values) {
        cout.width(15);  // align right with width=15
        cout.fill('*');  // padding
        cout << i << endl;
    }
}