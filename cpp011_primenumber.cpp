#include <iostream>
#include <vector>
using namespace std;


vector<int> findPrime(int n) {
    vector<int> primes;
    bool isPrime;
    for (int i=2; i<=n; i++) {
        isPrime = true;
        for (int j=2; i<j; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}


int main() {
    vector<int> ans = findPrime(200);
    cout << "Primes: ";
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << "\nDone" << endl;
    return 0;
}