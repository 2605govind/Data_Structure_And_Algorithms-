#include <bits/stdc++.h>
using namespace std;

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

class Solution{
    // Method for checking sum of child node is queal to parent or not
    int solver(Node* root,int &ans) {
        // If root point null then return o
        if(!root) return 0;
        
        // If root is leaf node then return leaf data
        if(!root->left && !root->right) {
            return root->data;
        }
        
        // Left contain left child of data
        int left = solver(root->left, ans);
        
        // Right contain right child of data
        int right = solver(root->right, ans);
        
        // Check sum is not equl to dta then initialize ans with 0
        if((left + right) != root->data) {
            ans = 0;
        }
        
        // Now, return child node data to perent
        return root->data;
    }
    public:
    int isSumProperty(Node *root)
    {
        // Assumen initially ans is 1 for tree follow give condition
        int ans = 1;
        // Solver method follow given condion and give right answer
        solver(root, ans);
        
        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    }
    return 0;
}

/* 10 10
    1
    
*/