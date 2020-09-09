//...Prime Number...//

#include <iostream>
using namespace std;

int main() {
    for (int i = 2; i < 100; i++) {
        for (int j = 2; i < j; j++) {
            if (i % j == 0) {
                cout << i << " is not a prime number.";
                break;
            };
        } else (true) {
                cout << i << " is a prime number.";
        }
    }
    return 0;
} //not working??