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

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val;
            temp = temp->next;
            if (temp != head)
                cout << " -> ";
        } while (temp != head);
        cout << " -> (back to " << head->val << ")\n";
    }

    void splitList(CircularLinkedList &first, CircularLinkedList &second) {
        if (!head)
            return;
        Node *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head)
            fast = fast->next;
        first.head = head;
        if (head->next != head)
            second.head = slow->next;
        fast->next = slow->next;
        slow->next = head;
    }
};

int main() {
    CircularLinkedList cll, firstHalf, secondHalf;
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cout << "Original Circular Linked List: ";
    cll.display();
    cll.splitList(firstHalf, secondHalf);
    cout << "First Half: ";
    firstHalf.display();
    cout << "Second Half: ";
    secondHalf.display();
    return 0;
}
