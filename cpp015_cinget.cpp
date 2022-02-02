#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    char str3[15];

    cout << "Input str1: " << endl;
    cin >> str1;  // reads input, but interrupted by whitespace
    cout << "str1: " << str1 << endl;

    // or

    cout << "Input str2: " << endl;
    cin.ignore();  // required if std::getline() is after std::cin
    std::getline(cin, str2);
    cout << "str2: " << str2 << endl;

    // or

    cout << "Input str3: " << endl;
    cin.get(str3, 15);  // reads input of char[] of length 15, ignores whitespaces
    cout << "str3: " << str3 << endl;

    return 0;
}
