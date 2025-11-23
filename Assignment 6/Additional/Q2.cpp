#include <iostream>
using namespace std;

class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int v) {
        val=v;
        next=prev=NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        DNode* n=new DNode(v);
        if (!head) {
            head = n;
            return;
        }
        DNode* temp=head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void removeEven() {
        DNode* temp=head;
        while (temp) {
            if (temp->val % 2 == 0) {
                DNode* del = temp;
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                temp = temp->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        DNode* temp = head;
        while (temp) {
            cout << temp->val;
            temp = temp->next;
            if (temp) cout << " <-> ";
        }
        cout << endl;
    }
};

class CNode {
public:
    int val;
    CNode* next;
    CNode(int v) {
        val = v;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        CNode* n = new CNode(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void removeEven() {
        if (!head) return;
        CNode *curr = head, *prev = NULL;
        do {
            if (curr->val % 2 == 0) {
                if (curr == head && curr->next == head) {
                    delete curr;
                    head = NULL;
                    return;
                }
                if (curr == head) {
                    CNode* tail = head;
                    while (tail->next != head)
                        tail = tail->next;
                    head = head->next;
                    tail->next = head;
                    CNode* del = curr;
                    curr = head;
                    delete del;
                    continue;
                } else {
                    prev->next = curr->next;
                    CNode* del = curr;
                    curr = curr->next;
                    delete del;
                    continue;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->val;
            temp=temp->next;
            if (temp!=head)
                cout << " -> ";
        } while (temp!=head);
        cout << " -> (back to " << head->val << ")\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);

    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);

    cout << "Doubly Linked List before deletion: ";
    dll.display();
    dll.removeEven();
    cout << "Doubly Linked List after deletion: ";
    dll.display();

    cout << "\nCircular Linked List before deletion: ";
    cll.display();
    cll.removeEven();
    cout << "Circular Linked List after deletion: ";
    cll.display();

    return 0;
}
