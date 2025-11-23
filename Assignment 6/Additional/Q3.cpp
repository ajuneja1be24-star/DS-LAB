#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    Node* reverseInGroups(Node* head, int k) {
        if (!head) return NULL;
        Node *curr = head, *prev = NULL, *next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            count++;
        }
        if (next)
            head->next = reverseInGroups(next, k);
        if (head->next)
            head->next->prev = head;
        return prev;
    }

    void reverseGroups(int k) {
        head = reverseInGroups(head, k);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val;
            temp = temp->next;
            if (temp) cout << " <-> ";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.insertAtEnd(7);

    int k = 3;
    cout << "Original List: ";
    dll.display();
    dll.reverseGroups(k);
    cout << "Reversed in groups of " << k << ": ";
    dll.display();

    return 0;
}
