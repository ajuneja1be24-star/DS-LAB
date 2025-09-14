#include <iostream>
#include <stack>
using namespace std;
class MinStack {
    stack<int> s;       
    stack<int> minStack; 
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    void pop() {
        if (s.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    int top() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return s.top();
    }
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minStack.top();
    }
    bool isEmpty() {
        return s.empty();
    }
};
int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);
    cout << "Current Min: " << ms.getMin() << endl;
    cout << "Top: " << ms.top() << endl;
    ms.pop();
    cout << "After popping, Min: " << ms.getMin() << endl;
    cout << "Top: " << ms.top() << endl;
    return 0;
}
