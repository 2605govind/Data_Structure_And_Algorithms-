//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution{
    public:
    
    // your task is to complete this function
    void sort(Node **head){
        if((*head)->next == NULL) ;
        
        Node* h1 = *head;
        Node* h2 = (*head)->next;
    
        Node* first = *head;
        Node* second = (*head)->next;
        

        while(second && second->next && first->next) {
            first->next = second->next;
            first = first->next;
    
            second->next = first->next;
            second = second->next;
        }
        
        // Reverse list
        Node* prev = NULL;
        Node* curr = h2;
        
        while(curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        second = prev;
        
        first->next = NULL;
        first = h1;
        
        // Merge technique
        Node* dummyNode = new Node(0);
        Node* dummy = dummyNode;
        
        while(first && second) {
            if(first->data <= second->data) {
                dummy->next = first;
                dummy = first;
                first = first->next;
            }else {
                dummy->next = second;
                dummy = second;
                second = second->next;
            }
        }
        
        if(first) {
            dummy->next = first;
        }
        
        if(second) {
            dummy->next = second;
        }
        
        *head = dummyNode->next;
        
        // *head = second;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends