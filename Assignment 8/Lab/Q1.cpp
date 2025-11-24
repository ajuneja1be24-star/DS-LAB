#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void order(Node*root){
    queue<Node*>q;
    q.push(root);
    while(q.size()){
        Node*temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
Node*construct(int arr[],int n){
    queue<Node*>q;
    Node*root=new Node(arr[0]);
    q.push(root);
    Node*l;
    Node*r;
    int i=1,j=2;
    while(q.size()&&i<n){
        Node*temp=q.front();
        q.pop();

        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        
        temp->left=l;
        temp->right=r;
        if(l) q.push(l);
        if(r) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}
void search(Node*root,int k){
    if(root==NULL) return;
    if(root->val==k) cout<<root->val<<" ";
    search(root->left,k);
    search(root->right,k);
}
void preorder(Node* root){
        if(root==NULL) return ;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
void postorder(Node* root){
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
    }
void inorder(Node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    }
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node*root=construct(arr,n);
    order(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
