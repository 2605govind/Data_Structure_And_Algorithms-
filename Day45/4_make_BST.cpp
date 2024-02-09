#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeBST(vector<int> &nums, int low, int high) {
    if(low > high) return NULL;
    int mid = (low + high)/2;
    
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = makeBST(nums, low, mid-1);
    root->right = makeBST(nums, mid+1, high);
    
    return root;
}


void print(TreeNode* root) {
    if(!root) return;
    
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main() {
    int n; 
    cin>>n; 
    
    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin>>nums[i];
    }
    
    TreeNode* root = makeBST(nums, 0, n-1);
    
    print(root);
    return 0;
}
