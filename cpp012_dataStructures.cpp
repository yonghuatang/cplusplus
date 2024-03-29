/* Some data structures in C++ ::: James Tang 02 Jan 2022 */

#include <bits/stdc++.h>
using namespace std;

/* === Three ways to declare/initialise an array === */

int arr1[5];  // array of size 5 storing integers
int arr2[] = {1, 2, 3, 4, 5};  // explicit initialisation
int arr3[5] = {1, 2, 3, 4, 5};  // declare the size and initialise elements at the same time


/* === Vector: dynamic arrays === */

vector<int> vec;
// vec.push_back()
// vec.size()


/* === Stack: last-in-first-out === */

stack<int> myStack;
// myStack.push()   push into the stack
// myStack.pop()    pop the top element
// myStack.top()    returns a reference of the top element
// myStack.empty()  checks if the stack is empty


/* === Queue: first-in-first-out, enqueue and dequeue === */

queue<int> q;
// q.push()   enqueue
// q.pop()    pop (dequeue) the front element
// q.front()  returns a reference of the front element
// q.empty()  checks if the queue is empty


/* === Priority queue: queue with sorting and priority dequeueing, default is max heap === */

priority_queue<int> pq1;
// pq.push()   enqueue
// pq.pop()    pop (dequeue) the top element (with highest priority thereof)
// pq.top()    returns a reference of the top element
// pq.empty()  checks if the priority_queue is empty

// while (!pq.empty()) {
//         cout << "Popping: " << pq.top() << endl;
//         pq.pop();
// }

// can also be used with comparators, for example min heap
struct comp {
    bool operator()(int a, int b) {    // function call operator overloading
        return a > b;
    }
};

priority_queue<int, vector<int>, comp> pq2;


/* === Deque: Double-ended queue === */

deque<int> dq;
// -- Typical member functions --
// dq.push_back()
// dq.push_front()
// dq.pop_back()
// dq.pop_front()
// dq.back()
// dq.front()
// dq.size()


/* === Set: container that stores unique elements === */

set<int> s;
// s.insert()


/* === Map: stores unique keys in sorted order === */

map<char, int> myMap;

// Initialise
// myMap['a'] = 10;
// myMap['b'] = 20;
// myMap['c'] = 30;
// myMap['d'] = 40;
// /* map<char, int>::iterator it; */
// for (auto it=myMap.begin(); it!=myMap.end(); it++) {
//     cout << it->first << "=>" << it->second << endl;
// }


/* === Pair: stores unique keys in sorted order === */

pair<int, int> myPair;

// auto p = std::make_pair(88, 99);
// cout << "Pair: " << myPair.first << " " << myPair.second << endl;


/* === Tuple: generalisation of std::pair, stores more than two elements === */

tuple<int, int, int> myTuple;

// myTuple = std::make_tuple(20, 30, 40);
// Use std::get<i>(t) to access a specific element of a tuple 't' at index 'i'


int main() {
    return 0;
}
