#include <iostream>
#include <vector>
using namespace std;

vector<int> result;

void findPrime(int n) {
    bool isPrime; 
    for (int i=2; i<=n; i++) {
        isPrime = false;
        for (int j=2; i<j; j++) {
            if (i % j == 0) {
                break;
            };
        } else { // ?? for-else
        }
    }    
}

int main() {
    findPrime(200);
    for (auto& i : result) {
        cout << i << endl;
    }
    return 0;
} //not working??