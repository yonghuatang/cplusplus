#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000007;

int main() {
    std::priority_queue<int> pq1;
    pq1.push(7);
    pq1.push(78);
    pq1.push(6);
    pq1.push(4);
    pq1.push(3);
    pq1.push(4);
    pq1.push(9789);
    pq1.push(6);
    std::priority_queue<int> pq2;
    pq2.push(1);
    pq2.push(4);
    pq2.push(34);
    pq2.push(5);
    pq2.push(6);
    pq2 = pq1;
    while (!pq2.empty()) {
        cout << pq2.top() << endl;
        pq2.pop();
    }
    cout << INF << endl;
    return 0;
}