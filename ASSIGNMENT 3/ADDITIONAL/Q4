#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[1000];
    int answer[1000] = {0};  
    stack<int> s;            

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int prevIndex = s.top();
            s.pop();
            answer[prevIndex] = i - prevIndex;
        }
        s.push(i);  
    }
    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
