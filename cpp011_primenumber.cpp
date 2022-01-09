#include <iostream>
#include <vector>
using namespace std;


// Find prime numbers within a range
vector<int> findPrime(int start, int end) {  // both inclusive
    vector<int> primes;
    bool isPrime;
    for (int i=start; i<=end; i++) {
        isPrime = true;
        for (int j=2; j<i; j++) {
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


// Check whether an integer is prime, returns -1 if not
int64_t checkPrime(uint64_t num) {
    int64_t divisor = -1;
    for (int i=2; i<num; i++) {
        if (num % i == 0) {
            divisor = i;
            break;
        }
    }
    return divisor;
}


int main() {
    auto ans = findPrime(3, 113);
    cout << "Primes: ";
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << "\nDone." << endl;

    uint64_t n;
    cout << "\n=== PRIMALITY TEST ===" << endl;
    cout << "Please enter an integer: ";
    cin >> n;
    cout << "The divisor is: " << checkPrime(n) << endl;
    return 0;
}