#include <iostream>
using namespace std;


// Trailing return type
template <typename T> auto addition(T a, T b) -> decltype(a+b) {
    return a + b;
}


// decltype(auto) (C++14)


int main() {
    decltype(auto) a = 9.5;
    typedef decltype("sdf") n;
    cout << a << endl;
    return 0;
}