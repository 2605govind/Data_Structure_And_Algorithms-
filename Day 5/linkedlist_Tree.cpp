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

// Template for (TreeNode)
class ListNode {
public:
    int data;
    TreeNode *root;
    ListNode *next;

    ListNode(TreeNode *x, int val) {
        data = val;
        root = x;
        next = NULL;
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

// Create a list :- very nodes have tree
ListNode* make_A_List(int n) {
    vector<int> ans = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    int index = 0;
    int val = 10;
    ListNode* head = NULL;

    // Create nth list node
    for (int i = 1; i<=n; i++) {
        ListNode* temp = new ListNode(Make_A_Tree(ans,index), val++);
        temp->next = head;
        head = temp;

        index = 0;
    }

    return head;
}

void preOrder(TreeNode* root){
    if(!root) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void print(ListNode *head) {
    if(!head) return;

    cout << head->data << " -> ";
    preOrder(head->root);
    cout << "\n\n";
    print(head->next);
}

int main(){
    int n = 5;

    // Make linkedlist and tree
    ListNode *head = make_A_List(5);

    print(head);
}
