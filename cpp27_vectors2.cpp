// Vector
// Start with an array

# include <iostream>
# include <string>
# include <vector>
using namespace std;

int main() {
    string arr[] = {"apple", "orange", "kiwi", "banana"};
    vector<string> fruit(arr, arr+sizeof(arr)/sizeof(string));
    for (string str: fruit) {
        cout << str << endl;
    }
    return 0;
}
