// template and decltype
// 10 December 2021 13:35

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> T1 addition(T1 a, T2 b) {
    return a + b;
}

template <typename T> void swapp(T* ptr_a, T* ptr_b) {
	const T temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}

int num = 0;

void increment(int& val) {
    val++;
}

void increment() {
    num++;
}

int main() {
    // treats 4.2 as float and 5.9 as int (truncated to become 5), returns float 9.2
    cout << addition<float, int>(4.2, 5.9) << endl;
    // auto type deduction, both treated as float, returns float 10.1 as in template
    cout << addition(4.2, 5.9) << endl;

    //
    int a = 5;
    int b = 7;
    // int* ptr_a = &a;
    // int* ptr_b = &b;
    swapp(&a, &b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    char c = 'a';
    char d = 'z';
    // char* ptr_c = &c;
    // char* ptr_d = &d;
    swapp(&c, &d);
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    
    return 0;
}