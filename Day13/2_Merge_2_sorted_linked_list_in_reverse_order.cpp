#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    Node* reverseList(Node* head){
        Node* prev = NULL;
        
        while(head) {
            Node* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    Node* mergList(Node* head1, Node* head2) {
        Node* dummyNode = new Node;
        Node* dummy = dummyNode;
        
        while(head1 && head2) {
            if(head1->data >= head2->data) {
                dummy->next = head1;
                dummy = head1;
                head1 = head1->next;
            }else {
                dummy->next = head2;
                dummy = head2;
                head2 = head2->next;
            }
        }
        
        if(head1){
            dummy->next = head1;
        }
        
        if(head2){
            dummy->next = head2;
        }
        
        head1 = dummyNode->next;
        delete dummyNode;
        
        
        return head1;
    }
    
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(!node1 && !node2) return NULL; 
        node1 = reverseList(node1);
        node2 = reverseList(node2);
        
        
        return mergList(node1,node2);
    }  
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
