#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> mySet = {1, 2, 4, 4, 4, 5, 6, 8, 8, 9};
    for (auto &element: mySet) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}