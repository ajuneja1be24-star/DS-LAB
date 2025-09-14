#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char x) {
        if (!isFull()) arr[++top] = x;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int k = 0; 
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            s.pop(); 
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix[k++] = s.pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
