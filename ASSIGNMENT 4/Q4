#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
void firstNonRepeating(string str) {
    unordered_map<char, int> freq; 
    queue<char> q;                 
    for (char ch : str) {
        // step 1: update frequency
        freq[ch]++;
        // step 2: push into queue
        q.push(ch);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}
int main() {
    string input = "aabc";  // you can take input from user also
    firstNonRepeating(input);
    return 0;
}
