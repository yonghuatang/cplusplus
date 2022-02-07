// Collatz Conjecture C++

#include <iostream>
using namespace std;

int main() {
    cout << "Please enter a number: ";
    long long n;
    cin >> n;
    long long count = 0;
    while (n != 1 && n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
        count++;
        cout << "Iteration " << count << ": " << n << endl; 
    }
    cout << "Number of iterations: " << count << endl; 
    return 0;
}
