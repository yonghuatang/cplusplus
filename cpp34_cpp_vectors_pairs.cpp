// Created by YongHua - 29 Jan 2021

#include <bits/stdc++.h>
using namespace std;

/* vectors are resizable arrays; pair is an associative data structure,
which groups two (may be different) data types. Here we are creating a vector
of pair.
*/
vector<pair<int, int>> myvector;
int arr1[] = {1, 2, 3, 4};
int arr2[] = {10, 20, 30, 40};

int main() {
    // in this case it's only valid if arr1 and arr2 have the same size
    // populating the vector
    int n = sizeof(arr1)/sizeof(arr1[0]);
    for (int i=0; i<n; ++i) {
        myvector.push_back(make_pair(arr1[i], arr2[i]));
    }
    
    // now print every element of each pair in the vector
    for (int i=0; i<n; ++i) {
        cout << myvector[i].first << " corresponds to " << myvector[i].second << endl;
    }
    // or:
    // for (auto item : myvector) {
    //     cout << item.first << " corresponds to " << item.second << endl;
    // }
    return 0;
}