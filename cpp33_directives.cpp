# include <bits/stdc++.h>
using namespace std;

// C++ preprocessor directives, or just simply 'macro'
# define ll long long
# define size(arr) sizeof(arr)/sizeof(arr[0])
# define getmax(a, b) (a>b?a:b)  // ternary operator, (expression ? true : false) 

ll num = 123456789123456789;

int main() {
    cout << getmax(2, 3) << endl;
    cout << num; 
    return 0;
}