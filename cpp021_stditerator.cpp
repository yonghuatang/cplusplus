#include <iostream>
#include <vector>
using namespace std;

typedef std::vector<int> vi_t;
// or
// using vi_t = std::vector<int>;

vi_t v = {1, 2, 3, 4, 5, 99};


int main() {
    /*
    // The usual way

    for (auto& i : v) {
        cout << i << endl;
        i++;
    }
    cout << "Done." << endl;
    */

    // Using iterators
    vi_t::iterator iter;  // pointer
    for (iter=v.begin(); iter<v.end(); iter++) {
        cout << *iter << endl;
    }
    cout << "Done." << endl;
    return 0;
}