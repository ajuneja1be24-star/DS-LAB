#include <iostream>
#include <vector>
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

vector<Node*> build(int l, int r) {
    if (l > r) return {NULL};
    vector<Node*> ans;
    for (int i = l; i <= r; i++) {
        vector<Node*> leftTrees = build(l, i - 1);
        vector<Node*> rightTrees = build(i + 1, r);
        for (Node* L : leftTrees) {
            for (Node* R : rightTrees) {
                Node* root = new Node(i);
                root->left = L;
                root->right = R;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<Node*> generateTrees(int n) {
    if (n == 0) return {};
    return build(1, n);
}

void preorder(Node* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<Node*> trees = generateTrees(n);

    for (auto t : trees) {
        preorder(t);
        cout << endl;
    }
}
