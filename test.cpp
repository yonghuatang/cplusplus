#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> weights = {1, 2, 3, 0, -1};
    for (auto i : weights) {
        cout << i << endl;
    }
    cout << weights.size() << endl;
    delete &weights;
    vector<int> weights{2, 3, 5};
    for (auto i : weights) {
        cout << i << endl;
    }
    cout << weights.size() << endl;
    return 0;
}