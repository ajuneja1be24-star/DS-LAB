#include <iostream>
using namespace std;

class DNode {
public:
    char val;
    DNode* next;
    DNode* prev;
    DNode(char v) {
        val = v;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(char v) {
        DNode* n = new DNode(v);
        if(!head) {
            head = n;
            return;
        }
        DNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void display() {
        DNode* temp = head;
        while(temp) {
            cout << temp->val;
            if(temp->next) cout << "<->";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if(!head || !head->next) return true;
        DNode* tail = head;
        while(tail->next) tail = tail->next;

        DNode* start = head;
        DNode* end = tail;

        while(start != end && start->prev != end) {
            if(start->val != end->val) return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string s = "radar"; 
    for(char c : s) dll.insertAtEnd(c);

    cout << "Doubly Linked List: ";
    dll.display();

    if(dll.isPalindrome()) cout << "The list is a palindrome\n";
    else cout << "The list is not a palindrome\n";

    return 0;
}
