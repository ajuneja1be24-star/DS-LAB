#include <iostream>
using namespace std;
#define SIZE 5
class cirqueue {
public:
    int arr[SIZE];
    int front;
    int rear;
    cirqueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {  // First insertion
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = val;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {  // Single element
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};
int main() {
    cirqueue q;
    int val;
    while (true) {
        cout << "Choose option 1. enqueue 2. dequeue 3. peek 4. display 5. exit: ";
        int n;
        cin >> n;
        switch (n) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
