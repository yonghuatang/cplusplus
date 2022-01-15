#include <iostream>
using namespace std;


// Trailing return type
template <typename T> auto addition1(T a, T b) -> decltype(a+b) {
    return a + b;
}


// decltype(auto) (since C++14)
template <typename T> decltype(auto) addition2(T a, T b) {
    return a + b;
}


int main() {
    cout << addition1(2.2, 3.3) << endl;
    cout << addition2(2.2, 3.3) << endl;
    return 0;
}