#include<iostream>
using namespace std;

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

Node *balanceTree(int array[], int start, int end){
    if(start > end)
    return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node(array[mid]);

    // make left side of tree
    root->left = balanceTree(array, start, mid-1);

    // make right side of tree
    root->right = balanceTree(array, mid+1, end);

    return root;
}

void preoder(Node *root){
    if(!root) return;

    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

int main(){
    // int arr[7] = {7,2,1,5,6,4,3};
    int arr[7] = {1,2,3,4,5,6,7};

    
    int n = 7;
    Node *root = balanceTree(arr, 0, n-1);

    preoder(root);
}
