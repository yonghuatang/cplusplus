#include <iostream>
using namespace std;


int findTriples(int arr[], int sizeOfArray) {
    int dp[sizeOfArray] = {0};
    int ans = 0;
    for (int i=0; i<sizeOfArray; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] % arr[j] == 0) {
                dp[i]++;
                ans += dp[j]; 
            }
        }
    }
    return ans;
}


int main() {
    int myArray[] = {1, 2, 3, 4, 6, 8, 12};
    int s_myArray = sizeof(myArray) / sizeof(myArray[0]);
    cout << "Size of array: " << s_myArray << endl; 
    cout << "Number of triples found: " << findTriples(myArray, s_myArray) << endl; 
    return 0;
}