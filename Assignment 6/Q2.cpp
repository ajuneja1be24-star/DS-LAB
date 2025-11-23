#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

class CircularList{
public:
    Node* head;
    CircularList(){
        head = NULL;
    }

    void insertAtEnd(int v){
        Node* n = new Node(v);
        if(!head){
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void display(){
        if(!head){
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do{
            cout << temp->val << "->";
            temp = temp->next;
        } while(temp != head);
        cout << head->val << endl; 
    }
};

int main(){
    CircularList cl;
    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);
    cl.insertAtEnd(40);

    cout << "Circular List: ";
    cl.display();

    return 0;
}
