#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    
    // This function is doing inserting all leafs one by one in vector
    void insertLeaf(TreeNode* root, vector<int> &leafs) {
        if(!root) return;

        insertLeaf(root->left, leafs);

        if(!root->left && !root->right){
            leafs.push_back(root->val);
        }

        insertLeaf(root->right, leafs);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        insertLeaf(root1, leafs1);
        insertLeaf(root2, leafs2);

        int n = leafs1.size();
        int m = leafs2.size();

        // If size is not equal then return false 
        if(n != m) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            // Checking all elements one by one if not equal then return false
            if(leafs1[i] != leafs2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    
}
