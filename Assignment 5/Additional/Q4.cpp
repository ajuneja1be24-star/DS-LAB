#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    Node* tail = head;
    int count = 1;

    while (tail->next != NULL) {
        tail = tail->next;
        count++;
    }

    k = k % count;
    if (k == 0) return head;

    tail->next = head;

    Node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    head = rotateLeft(head, k);
    printList(head);

    return 0;
}
