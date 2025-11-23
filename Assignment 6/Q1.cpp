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

class DoublyCircularList {
public:
    Node* head;
    DoublyCircularList() {
        head = NULL;
    }

    void insertAtBeginning(int v) {
        Node* n = new Node(v);
        if(!head) {
            n->next = n->prev = n;
            head = n;
            return;
        }
        Node* tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = head->prev = n;
        head = n;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if(!head) {
            n->next = n->prev = n;
            head = n;
            return;
        }
        Node* tail = head->prev;
        tail->next = n;
        n->prev = tail;
        n->next = head;
        head->prev = n;
    }

    void insertAfter(int key, int v) {
        if(!head) return;
        Node* temp = head;
        do {
            if(temp->val == key) {
                Node* n = new Node(v);
                Node* nextNode = temp->next;
                temp->next = n;
                n->prev = temp;
                n->next = nextNode;
                nextNode->prev = n;
                return;
            }
            temp = temp->next;
        } while(temp != head);
    }

    void insertBefore(int key, int v) {
        if(!head) return;
        Node* temp = head;
        do {
            if(temp->val == key) {
                Node* n = new Node(v);
                Node* prevNode = temp->prev;
                n->next = temp;
                n->prev = prevNode;
                prevNode->next = temp->prev = n;
                if(temp == head) head = n;
                return;
            }
            temp = temp->next;
        } while(temp != head);
    }

    void deleteNode(int key) {
        if(!head) return;
        Node* temp = head;
        do {
            if(temp->val == key) {
                if(temp->next == temp) {
                    delete temp;
                    head = NULL;
                    return;
                }
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                if(temp == head) head = nextNode;
                delete temp;
                return;
            }
            temp = temp->next;
        } while(temp != head);
    }

    void search(int key) {
        if(!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if(temp->val == key) {
                cout << "Found " << key << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while(temp != head);
        cout << key << " not found\n";
    }

    void display() {
        if(!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val;
            temp = temp->next;
            if(temp != head) cout << "<->";
        } while(temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularList l;
    int choice, val, key;
    while(true) {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After a Node";
        cout << "\n4. Insert Before a Node";
        cout << "\n5. Delete a Node";
        cout << "\n6. Search a Node";
        cout << "\n7. Display";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: 
                cout << "Enter value: ";
                cin >> val;
                l.insertAtBeginning(val);
                break;
            case 2: 
                cout << "Enter value: ";
                cin >> val;
                l.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter node value to insert after: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                l.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter node value to insert before: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                l.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                l.deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                l.search(key);
                break;
            case 7:
                l.display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
