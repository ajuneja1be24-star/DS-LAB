#include <iostream>
using namespace std;

class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int v){
        val = v;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList(){
        head = NULL;
    }

    void insertAtEnd(int v){
        DNode* n = new DNode(v);
        if(!head){
            head = n;
            return;
        }
        DNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size(){
        int count = 0;
        DNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display(){
        DNode* temp = head;
        while(temp){
            cout << temp->val;
            if(temp->next) cout << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    dll.display();
    cout << "Size of Doubly Linked List: " << dll.size() << endl;

    return 0;
}
