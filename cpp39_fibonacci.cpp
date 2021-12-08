#include<bits/stdc++.h>
using namespace std;

#define ll long long

int fib(int n) {
    ll f[n+2];
    ll i;
    f[0] = 0;  // the two base cases
    f[1] = 1;
    for (ll i=2; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main() {
    cout << "Please enter a number: " << endl;
    int num;
    cin >> num; 
    cout << "The answer is " << fib(num) << endl;
    return 0;
}