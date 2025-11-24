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

Node* build(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe, unordered_map<int,int>& mp) {
    if (is > ie || ps > pe) return NULL;
    Node* root = new Node(post[pe]);
    int idx = mp[root->val];
    int leftSize = idx - is;
    root->left = build(in, is, idx - 1, post, ps, ps + leftSize - 1, mp);
    root->right = build(in, idx + 1, ie, post, ps + leftSize, pe - 1, mp);
    return root;
}

Node* buildTree(vector<int>& in, vector<int>& post) {
    unordered_map<int,int> mp;
    for (int i = 0; i < in.size(); i++) mp[in[i]] = i;
    return build(in, 0, in.size() - 1, post, 0, post.size() - 1, mp);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> post = {9, 15, 7, 20, 3};
    Node* root = buildTree(in, post);
    preorder(root);
}
