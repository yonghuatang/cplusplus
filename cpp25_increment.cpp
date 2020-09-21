# include <iostream>
using namespace std;

// ++i vs i++

void plusplus_i() {
    for (int i=0; i<=10; ++i) {
        cout << i << " ";
    }
}

void i_plusplus() {
    for (int i=0; i<=10; i++) {
        cout << i << " ";
    }
}

int main() {
    plusplus_i();
    cout << endl;
    i_plusplus();
    return 0;
}