#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if(!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
    }

    void makeCircular() {
        if(!head) return;
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if(!head) return false;
        Node* temp = head->next;
        while(temp != NULL && temp != head) temp = temp->next;
        return (temp == head);
    }
    void display(int n = 20) { 
        Node* temp = head;
        int count = 0;
        while(temp && count < n) {
            cout << temp->val << "->";
            temp = temp->next;
            count++;
        }
        if(temp == head) cout << "(head)";
        else cout << "NULL";
        cout << endl;
    }
};

int main() {
    LinkedList l1, l2;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    
    l2.insertAtEnd(10);
    l2.insertAtEnd(20);
    l2.insertAtEnd(30);
    l2.makeCircular();

    cout << "List 1: ";
    l1.display();
    cout << "Is List 1 Circular? " << (l1.isCircular() ? "Yes" : "No") << endl;

    cout << "List 2: ";
    l2.display();
    cout << "Is List 2 Circular? " << (l2.isCircular() ? "Yes" : "No") << endl;

    return 0;
}
