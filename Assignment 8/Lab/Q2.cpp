#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

Node* constructBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] != INT_MIN) 
            root = insertBST(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int maxDepth(Node* root) {
    if(root==NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;
    while (root) {
        if (target->val < root->val) {
            succ = root;
            root = root->left;
        } else
            root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;
    while (root) {
        if (target->val > root->val) {
            pred = root;
            root = root->right;
        } else
            root = root->left;
    }
    return pred;
}

Node* search(Node* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int arr[] = {10, 5, 20, 3, 8, 15, 25, INT_MIN, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = constructBST(arr, n);
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    int key = 8;
    Node* target = search(root, key);
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);
    
    if (succ) cout << "Inorder Successor of " << key << ": " << succ->val << endl;
    else cout << "No Inorder Successor for " << key << endl;

    if (pred) cout << "Inorder Predecessor of " << key << ": " << pred->val << endl;
    else cout << "No Inorder Predecessor for " << key << endl;
}
