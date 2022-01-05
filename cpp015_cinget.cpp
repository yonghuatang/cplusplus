#include <iostream>
using namespace std;


int main() {
    // cin.get() is sometimes useful than cin
    cout << "\n" << "=== cin.get() ===" << endl;
    string str1;
    char str2[25];
    cout << "Input: " << endl;
    // cin >> str1;  // reads input, but interrupted by whitespace
    // or
    cin.get(str2, 25);  // reads input of char of length 25, ignores whitespaces
    cout << "Output: \n" << str2 << endl;
    return 0;
}
