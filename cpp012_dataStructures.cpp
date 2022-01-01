/* Some data structures in C++ ::: James Tang 02 Jan 2022 */

#include <bits/stdc++.h>
using namespace std;

/* Three ways to declare/initialise an array */

int arr1[5];  // array of size 5 storing integers
int arr2[] = {1, 2, 3, 4, 5};  // explicit initialisation
int arr3[5] = {1, 2, 3, 4, 5};  // declare the size and initialise elements at the same time


/* Vectors are dynamic arrays */

vector<int> vec;
// vec.push_back()
// vec.size()


/* Stack: last-in-first-out */

stack<int> myStack;
// myStack.push()  push into the stack
// myStack.pop()  pop the top element
// myStack.top()  returns a reference of the top element
// myStack.empty()  checks if the stack is empty


/* Queue: first-in-first-out, enqueue and dequeue */

queue<int> q;
// myStack.push()  push into the stack
// myStack.pop()  pop the top element
// myStack.front()  returns a reference of the top element
// myStack.empty()  checks if the stack is empty


/* Priority queue: queue with sorting and priority dequeueing, default is max heap*/

priority_queue<int> pq1;
// pq.push()  push into the stack
// pq.pop()  pop the top element
// pq.top()  returns a reference of the top element
// pq.empty()  checks if the stack is empty

// can also be used with comparators, for example min heap
struct comp {
    bool operator()(int a, int b) {    // function call operator overloading
        return a > b;
    }
};

priority_queue<int, vector<int>, comp> pq2;


/*  */

int main() {
    return 0;
}

