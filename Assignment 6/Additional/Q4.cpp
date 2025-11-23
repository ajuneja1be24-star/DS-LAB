#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node* random;
    Node(int v) {
        val = v;
        next = prev = random = NULL;
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

    void assignrandompointers() {
        Node* temp = head;
        while (temp)
            temp->random = temp, temp = temp->next;
    }

    void introduceerror() {
        if (head && head->next && head->next->next)
            head->next->random = head->next->next->next;
    }

    void correctrandompointer() {
        Node* temp = head;
        while (temp) {
            if (temp->random != temp)
                temp->random = temp;
            temp = temp->next;
        }
    }

    void displayRandoms() {
        Node* temp = head;
        while (temp) {
            cout << "Node " << temp->val << " -> Random " << temp->random->val << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    for (int i = 1; i <= 6; i++)
        dll.insertAtEnd(i);

    dll.assignrandompointers();
    dll.introduceerror();

    cout << "Before correction:\n";
    dll.displayRandoms();

    dll.correctrandompointer();

    cout << "\nAfter correction:\n";
    dll.displayRandoms();

    return 0;
}
