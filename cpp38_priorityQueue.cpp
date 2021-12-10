// std::priority_queue
// 10 December 2021 13:13
// methods: push(), top(), empty(), pop()

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::priority_queue<int> pq;  // a queue but with priority, default sort is max 
    pq.push(2);
    pq.push(34);
    pq.push(5);
    pq.push(0);
    pq.push(7);
    cout << "The largest element is: " << pq.top() << endl;
    while (!pq.empty()) {
        cout << "Popping: " << pq.top() << endl;
        pq.pop();
    }
    return 0;
}