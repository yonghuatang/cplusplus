// C++ Exception Handling
#include <iostream>
using namespace std;


int main() {
    int a, b;
    string result = "None";
    cout << "Please input two integers 'a' and 'b' such that a / b will be calculated: ";
    cin >> a >> b;

    try {
        if (b == 0) {
            throw b;
        }
        result = to_string(a / b);
    }
    catch (int e) {
        cout << "Error: Zero-division is not permissible!" << endl;
    }
    catch (...) {
        cout << "Default exception occurred!" << endl;
    }

    cout << "The answer is: " << result << endl;
    return 0;
}