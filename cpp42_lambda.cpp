#include <iostream>
using namespace std;


int main() {
    cout << [](const int value){return value + 1;}(9); // ??
    return 0;
}    
