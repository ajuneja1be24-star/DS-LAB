#include <iostream>
#include <vector>
#include <unordered_map>
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

Node* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& mp) {
    if (ps > pe || is > ie) return NULL;
    Node* root = new Node(pre[ps]);
    int idx = mp[root->val];
    int leftSize = idx - is;
    root->left = build(pre, ps + 1, ps + leftSize, in, is, idx - 1, mp);
    root->right = build(pre, ps + leftSize + 1, pe, in, idx + 1, ie, mp);
    return root;
}

Node* buildTree(vector<int>& pre, vector<int>& in) {
    unordered_map<int,int> mp;
    for (int i = 0; i < in.size(); i++) mp[in[i]] = i;
    return build(pre, 0, pre.size() - 1, in, 0, in.size() - 1, mp);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    Node* root = buildTree(pre, in);
    preorder(root);
}
