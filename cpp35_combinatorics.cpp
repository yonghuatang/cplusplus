// Created by YongHua - 30 Jan 2021

# include <iostream>
using namespace std;

// calculate factorial (n!) using recursion
int fact(int n) {
    if (n==0) {
        return 1;
    } else if (n <= 2) {
        return n; 
    } else {
        return n * fact(n-1);
    }
}

// Binomial coefficient n_C_k - to calculate no. of combinations
int bc(int n, int k) {
    if (k==0 || k==n) {
        return 1;
    } else {
        return bc(n-1, k-1) + bc(n-1, k);
    }
}

// or using factorial definiton,
int bcfact(int n, int k) {
    return fact(n) / (fact(k) * fact(n-k));
}


int main() {
    cout << fact(10) << endl;  // returns factorial of 10
    cout << bc(5, 3) << endl;  // returns 10
    cout << bcfact(5, 3) << endl;
    return 0;
}
