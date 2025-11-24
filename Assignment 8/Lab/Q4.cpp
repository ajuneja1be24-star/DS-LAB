#include <iostream>
#include <limits.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};

Node *build(Node *root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;

    if (d == -1)
        return NULL;

    root = new Node(d);

    cout << "Enter LEFT child of " << d << endl;
    root->left = build(root->left);

    cout << "Enter RIGHT child of " << d << endl;
    root->right = build(root->right);

    return root;
}

bool isBST(Node *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

void inorder(Node *&root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = build(root);
    cout << "\nPRINTING INORDER TRAVERSAL:";
    inorder(root);
    if (isBST(root, INT_MIN, INT_MAX))
    {
        cout << "\nENTERED TREE IS A BST.";
    }
    else
        cout << "NOT A BST.\n";
}
