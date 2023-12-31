// Linked list and tree both combination data structure implement by ~ Govind Suthar
#include<bits/stdc++.h>
using namespace std;

// Template for (TreeNode)
class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }


};


// Create a tree
TreeNode* Make_A_Tree (vector<int> &ans, int &index) {
    if (ans[index] == -1) {
        return NULL;
    } else {
        TreeNode* root = new TreeNode(ans[index]);
        index++;
        root->left = Make_A_Tree(ans, index);
        index++;
        root->right = Make_A_Tree(ans, index);

        return root;
    }
}


void preOrder(TreeNode* root, vector<vector<char>> &graphic_rep, int size,int row){
    if(!root) return;

    int pos = size / 2;
    graphic_rep[row][pos] = '0' + root->data;
    if (!root->left && !root->right) {
        return;
    }
    graphic_rep[row+1][pos-1] = '|'; 
    graphic_rep[row+1][pos+1] = '|'; 

    preOrder(root->left, graphic_rep, pos, row+2);
    preOrder(root->right, graphic_rep, pos+5, row+2);
}


int main(){
    vector<int> ans = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    int index = 0;
    TreeNode* root = Make_A_Tree(ans,index);

    vector<vector<char>> graphic_rep(5, vector<char> (5,' '));
    preOrder(root, graphic_rep, 5, 0);

    for (int i = 0; i < 5; i++) {
        for (int j=0; j < 5; j++) {
            cout<<graphic_rep[i][j] << " ";
        }
        cout << "\n";
    }
}
