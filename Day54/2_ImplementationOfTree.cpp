#include<iostream>
using namespace std;

// basic Tree Node template
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* binaryTree(){
    int x;
    cout<<"Enter the value ";
    cin>>x;
    if(x == -1)
        return NULL;

    Node* root = new Node(x);
    cout<<"Enter the Left child "<<x<<"\n";
    root->left = binaryTree();
    cout<<"Enter the Right child "<<x<<"\n";
    root->right = binaryTree();

    return root;
}

int main(){
    Node* root = binaryTree();
}


