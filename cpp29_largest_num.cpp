# include <iostream>
using namespace std;

int bignum = 0;

int main() {
    while (true) {
        cout << "Please enter an integer (type 0 to exit): ";
        int n;
        cin >> n;
        if (n==0) {
            break;
        }
        if (n>bignum) {
            bignum = n;
        }
    }
    cout << "The largest number is: " << bignum << endl;
    return 0;
}