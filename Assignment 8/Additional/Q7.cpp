#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}
void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (!head) head = root;       
    else {
        prev->right = root;   
        root->left = prev;
    }

    prev = root;               

    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    while (a && b) {
        Node* temp;
        if (a->val < b->val) {
            temp = a;
            a = a->right;
        } else {
            temp = b;
            b = b->right;
        }

        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    while (a) {
        tail->right = a;
        a->left = tail;
        tail = a;
        a = a->right;
    }
    while (b) {
        tail->right = b;
        b->left = tail;
        tail = b;
        b = b->right;
    }

    return head;
}
Node* mergeTwoBSTs(Node* root1, Node* root2) {
    Node *h1 = NULL, *p1 = NULL;
    bstToDLL(root1, h1, p1);

    Node *h2 = NULL, *p2 = NULL;
    bstToDLL(root2, h2, p2);

    return mergeDLL(h1, h2);
}

void printDLL(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
}

int main() {
    int arr1[] = {4, 2, 6, 1, 3};
    Node* root1 = NULL;
    for (int x : arr1) root1 = insertBST(root1, x);

    int arr2[] = {5, 3, 7};
    Node* root2 = NULL;
    for (int x : arr2) root2 = insertBST(root2, x);

    Node* head = mergeTwoBSTs(root1, root2);

    cout << "Merged DLL in sorted order: ";
    printDLL(head);
}
