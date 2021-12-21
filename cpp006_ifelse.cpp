#include <iostream>
using namespace std;

// int main() {
//     int x;
//     int y;
//     cout << "Please enter an integer 'x': ";
//     cin >> x;
//     cout << "Please enter an integer 'y': ";
//     cin >> y;
//     if (x >= y) {
//         cout << x << " is greater or equal than " << y;
//     }
//     else {
//         cout << x << " is smaller than " << y;
//     }
//     return 0;
// }


// ternary if-else statement
int main() {
    int x;
    int y;
    cout << "Please enter an integer 'x': ";
    cin >> x;
    cout << "Please enter an integer 'y': ";
    cin >> y;
    cout << x << " is " << ((x>=y) ? "greater or equal" : "smaller") << " than " << y;
    return 0;
}