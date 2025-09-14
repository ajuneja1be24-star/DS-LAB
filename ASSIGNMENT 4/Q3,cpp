#include <iostream>
#include <queue>
using namespace std;
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }
    int half = n / 2;
    queue<int> firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    interleaveQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
