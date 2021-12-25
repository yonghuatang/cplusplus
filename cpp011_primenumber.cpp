#include <iostream>
#include <vector>
using namespace std;


void findPrime(int n, vector<int> results) {
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
    vector<int> ans;
    findPrime(200, ans);
    for (auto& i : ans) {
        cout << i << endl;
    }
    return 0;
} //not working??