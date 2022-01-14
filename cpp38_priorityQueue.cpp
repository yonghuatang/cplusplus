// std::priority_queue
// 10 December 2021 13:13
// methods: push(), top(), empty(), pop()

#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

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
    cout << "\n";

    std::priority_queue<int, vector<int>, comp> pq1;  // priority is min, using comparators 
    pq1.push(2);
    pq1.push(34);
    pq1.push(5);
    pq1.push(0);
    pq1.push(7);
    cout << "The smallest element is: " << pq1.top() << endl;
    while (!pq1.empty()) {
        cout << "Popping: " << pq1.top() << endl;
        pq1.pop();
    }

    return 0;
}