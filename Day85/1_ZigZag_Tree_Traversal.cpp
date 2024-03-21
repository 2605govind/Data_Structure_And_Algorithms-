//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution_1{
    void solve(Node* root, vector<vector<int>> &vec, int l) {
        if(root == nullptr) return;
        
        if(vec.size() < l+1) {
            vec.resize(vec.size()+1);
        }
        
        vec[l].push_back(root->data);
        
        solve(root->left, vec, l+1);
        solve(root->right, vec, l+1);
    }
    
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
        vector<int> ans;
        
        vector<vector<int> > vec;
        
        solve(root, vec, 0);
        
        bool flag = 0;
        for(auto x : vec) {
            if(flag) {
                reverse(x.begin(), x.end());
                flag = 0;
            }else {
                flag = 1;
            }
            
            for(auto k : x) {
                ans.push_back(k);
            }
        }
        
        return ans;
    }
};

class Solution_2{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        
        bool flag = 0;
        
        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();
            
            while(size--) {
                Node* node = q.front();
                temp.push_back(node->data);
                q.pop();
                
                
                if(node->left) 
                q.push(node->left);
                
                if(node->right) 
                q.push(node->right);
            }
            
            if(flag) {
                reverse(temp.begin(), temp.end());
                flag = 0;
            }else {
                flag = 1;
            }
                
            for(auto x : temp) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution_2 ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends   

/*
https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

Input:
4 7 0 4 0 N N N N N N
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
Output:
1 3 2 4 5 6 7

*/