// template and decltype
// 10 December 2021 13:35

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> T1 addition(T2 a, T2 b) {
    return a + b;
}

template <typename T> void swapp(T* ptr_a, T* ptr_b) {
	T temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp; 
}


void increment(int& val) {
    val++;
}

int main() {
    // cout << addition<float, int>(4, 5) << endl;
    // cout << addition(4, 5) << endl;
    // echo([](const int value){return value + 1;}(9));

    int p = 10;
    // int& y = p;
    // echo(p);
    // echo(y);
    // echo(&p);
    // echo(&y);
    cout << p << endl;
    increment(p);
    cout << p << endl;
    int a = 5;
    int b = 7;

    return 0;
}