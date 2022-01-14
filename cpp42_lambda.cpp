// C++ Lambda Expressions
#include <iostream>
#include <vector>
using namespace std;

vector<int> v{1, 2, 4, 7, 11, 99};


int main() {
    int num = 100;

    auto f = [](int i){
    cout << i << " ";
    };

    auto g = [&num](int i) mutable {
    cout << i+num << " ";
    num++;;
    };

    cout << "f: ";
    for (auto i : v) {
        f(i);
    }

    cout << "\n" << "g: ";
    for (auto i : v) {
        g(i);
    }

    cout << "\n" << [=](const int value){ return value + num; }(9) << endl;  // however redundant
    // cout << 9 + num << endl; will do the same job
    return 0;
}    
