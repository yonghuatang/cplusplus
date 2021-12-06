// Tang - 6th December 2021 12:09 PM
// Dynamic programming for weighted checkerboard-like questions

#include <bits/stdc++.h>
using namespace std;

int inf = pow(10, 9) + 7;

int main() {
    vector<vector<int>> cost(8, vector<int>(8, 0));
    vector<vector<int>> dp(8, vector<int>(8, inf));
    int m, n;
    cin >> m >> n;
    for (int i=7; i>=0; i--) {  // mirror (flip) the board for easier implementation
        for (int j=0; j<=7; j++) {
            cin >> cost[i][j];
        }
    }
    dp[0][0] = cost[0][0];  // initialise the matrix
    for (int i=0; i<=7; i++) {
        for (int j=0; j<=7; j++) {
            // we won't walk up or left because we want to find the path with least weight
            if (i+1<8) {  // if we can walk right
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+cost[i+1][j]);
            }
            if (j+1<8) {  // if we can walk down
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+cost[i][j+1]);
            }
            if (i+1<8 && j+1<8) {  // if we can walk diagonally down-right
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+cost[i+1][j+1]);
            }
        }
    }
    cout << "The minimum cost to (" << m << ", " << n << ") is " << dp[m][n] << endl;
    return 0;
}