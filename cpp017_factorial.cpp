#include <iostream>
using namespace std;

uint64_t fact(int num) {
    uint64_t ans = 1;
    if (num<=1) {
        return ans;
    }
    for (int i=1; i<=num; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << fact(n);
    return 0;
}