# include <iostream>
# include <string>
using namespace std;

int main() {
    // scanf and printf
    cout << "=== scanf and printf ===" << endl;
    int num1;
    int num2;
    cout << "Please input two numbers separated by whitespace: ";
    scanf("%d %d", &num1, &num2);
    printf("Number: %d %d \n", num1, num2);
}
