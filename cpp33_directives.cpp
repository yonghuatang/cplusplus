#pragma once  // prevent duplicate inclusion

#include <bits/stdc++.h>
using namespace std;

// C++ preprocessor directives, or just simply 'macro'. Eaxmples:
#define PI 3.142
#define ll long long
#define size(arr) sizeof(arr)/sizeof(arr[0])
#define getmax(a, b) (a>b?a:b)  // ternary operator, (expression ? true : false) 
#define echo(x) std::cout << x << std::endl

/*
Other directives:
#ifdef
#ifndef
#undef
#endif
#if
#elif
#else
*/

ll num = 123456789123456789;

int main() {
    cout << getmax(2, 3) << endl;
    cout << num; 
    return 0;
}
