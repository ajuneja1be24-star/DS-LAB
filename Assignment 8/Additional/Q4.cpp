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

vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            Node* cur = q.front();
            q.pop();
            if (i == n) ans.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, INT_MIN, 5, INT_MIN, 4};
    Node* root = buildTree(arr);
    vector<int> res = rightView(root);
    for (int x : res) cout << x << " ";
}
