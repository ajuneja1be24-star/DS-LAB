#include <iostream>
#include <vector>
#include <queue>
#include<climits>
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

Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();
        if (arr[i] != INT_MIN) {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i] != INT_MIN) {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int sumLeft(Node* root, bool isLeft) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL && isLeft) return root->val;
    return sumLeft(root->left, true) + sumLeft(root->right, false);
}

int sumOfLeftLeaves(Node* root) {
    return sumLeft(root, false);
}

int main() {
    vector<int> arr = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    Node* root = buildTree(arr);
    cout << sumOfLeftLeaves(root);
}
