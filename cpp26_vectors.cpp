# include <iostream>
# include <string>
# include <vector>
using namespace std;

int main() {
    vector<int> rooms(9);   // vector <type> variable(elements)
    for (int x: rooms) {
        cout << x << endl;
    }
    return 0;
}

/* 
-- Iterators --
vector::begin() returns an iterator to point at the first element of a C++ vector.
vector::end() returns an iterator to point at past-the-end element of a C++ vector.
vector::cbegin() is similar to vector::begin(), but without the ability to modify the content.
vector::cend() issimilar to vector::end() but can’t modify the content.
*/

/*
-- Modifiers --
vector::push_back() pushes elements from the back.
vector::insert() inserts new elements to a specified location.
vector::pop_back() removes elements from the back.
vector::erase() removes a range of elements from a specified location.
vector::clear() removes all elements.
*/