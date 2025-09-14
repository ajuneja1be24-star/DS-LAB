#include <iostream>
#include <cstring>
#include <cmath>  
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1; 
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        return -1;
    }
};
int evaluatePostfix(char postfix[]) {
    Stack s;

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0'); 
        }
        
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter a postfix expression: ";
    cin.getline(postfix, MAX);

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
