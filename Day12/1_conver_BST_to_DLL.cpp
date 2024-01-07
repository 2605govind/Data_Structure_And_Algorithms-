// converting BST to DLL
#include<iostream>
#include<queue>
using namespace std;

// Tree node template
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val  = x;
        left = right = nullptr;
    }
};

// Built Binary search tree using given array
class TreeFuntion {
    public:

    TreeNode* buildTree(int array[], int i, int j) {
        if(i > j) return NULL;

        int mid = (i + j) / 2;

        TreeNode* root = new TreeNode(array[mid]);

        root->left = buildTree(array, i, mid-1);
        root->right = buildTree(array, mid+1, j);

        return root;
    }

    void inOrder(TreeNode* root) {
        if(!root) return ;

        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
};


// doubly linked list node template
class DoublyNode {
    public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(int x) {
        data = x;
        next = prev = nullptr;
    }
};

// class for doubly linked list function
class DoublyFunction {
    public:

    bool chechDoublyLinkedListOrNot(DoublyNode* head) {
        DoublyNode* prev = NULL;

        while(head) {
            if(head->prev != prev) {
                return 0;
            }
            prev = head;
            head = head->next;
        }

        return 1;
    }

    void print(TreeNode* head) {
        TreeNode* curr = head;
        TreeNode* prev;

        while(curr) {
            cout<<curr->val<<" ";
            prev = curr;
            curr = curr->right;
        }
        cout<<endl;
        
        while(prev) {
            cout<<prev->val<<" ";
            prev = prev->left;
        }

    }
};


// Solution of converting BST to DLL 

// Soution 1 Worse Case TC O(N) & SC O(N) || external space of nodes
class Solution_1 {
    public:
    
    void convertBstToDll(TreeNode* root, DoublyNode* &prev, DoublyNode* &roothead, bool &flag ) {
        if(!root) return ;

        convertBstToDll(root->left, prev, roothead,flag);

        DoublyNode* head = new DoublyNode(root->val);
        head->prev = prev;

        if(prev) prev->next = head;
        if(flag) 
            roothead = head, flag = 0;
        prev = head;
        convertBstToDll(root->right, prev, roothead,flag);
    }
};


// Soution 2 Worse Case TC O(N) & SC O(N) || internal nodes with queue space
class Solution_2 {
    queue<TreeNode*> q;
    void insertInQueue(TreeNode* root) {
        if(!root) return;

        insertInQueue(root->left);
        q.push(root);
        insertInQueue(root->right);
    }

    public:
    TreeNode* convertBstToDll(TreeNode* root) {
        insertInQueue(root);

        TreeNode* prev = NULL;
        TreeNode* head = q.front();
        TreeNode* curr = q.front();
        
        while(!q.empty()) {
            curr->right = q.front();
            curr = q.front();
            q.pop();
        } 
        curr->right = NULL;
        curr = head;
        while(curr) {
            curr->left = prev;
            prev = curr;
            curr = curr->right;
        }

        return head;
    }

};

// Solution 3 best optimize solution TC O(N)  &&  SC O(1) internal space
class Solution_3 {
    TreeNode* makeLinkedList(TreeNode* root, TreeNode* &head) {
        if(!root) return NULL;

        makeLinkedList(root->left, head);
        head->right = root;
        head = root;
        makeLinkedList(root->right, head);
        
    }
    public:

    TreeNode* convertBstToDll(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* head = dummy;

        makeLinkedList(root, head);

        head->right = NULL;
        TreeNode* prev = NULL;
        TreeNode* temp = dummy->right;

        head = dummy->right;
        while(head) {
            head->left = prev;
            prev = head;
            
        // cout<<head->val<<" ";
            head = head->right;
        }
        delete dummy;
        head = temp;

        return head;
    }    
};

int main() {
    int array[] = {1, 3, 2};
    int n = 3;

    TreeFuntion tf;
    TreeNode* root = tf.buildTree(array, 0, n-1); 

    // tf.inOrder(root);


    // Solution 1 _________________________

    // Solution_1 s1;
    // DoublyNode* prev = NULL;
    // DoublyNode* head;
    // bool flag = 1;
    // s1.convertBstToDll(root, prev, head, flag);

    // DoublyFunction df;
    // if(df.chechDoublyLinkedListOrNot(head)){
    //     cout<<"\n Doubly Linked List";
    // }
    
    // __________________________________


    // Solution 2 _________________________

    Solution_2 s2;
    TreeNode* head = s2.convertBstToDll(root);

    DoublyFunction df;
    df.print(head);

    // __________________________________



    // Solution 3 _________________________
    // Solution_3 s3;

    // TreeNode* head = s3.convertBstToDll(root);

    // DoublyFunction df;
    // df.print(head);
    // __________________________________


    return 0;
}