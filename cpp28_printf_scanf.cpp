# include <iostream>
# include <string>
using namespace std;

int main() {
    // scanf and printf
    int num;
    char word;
    scanf("%d, %c", &num, &word);
    printf("%d, %c", num, word);
    
    // cin.get()
    string str;
    cout << "Input: " << endl;
    // cin >> str;  // reads input, but interrupted by whitespace
    // or
    cin.get(str, 25)  // reads input of char of length 25, ignores whitespaces
    cout << "Output: " << str << endl;
    return 0;
}
