#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data, Node *prev = nullptr, Node *next = nullptr)
        : data(data), prev(prev), next(next) {}
 
    void insertNode(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (!head)
            head = newNode;
        else
            newNode->next = head, head->prev = newNode, head = newNode;
    }

    void printList(Node *head)
    {   
        Node* curr = head;
        Node* prevCurr;
        while (curr)
        {
            cout<<curr->data<<" ";
            if(!curr->next) prevCurr = curr;
            curr = curr->next;
        }
        cout<<"\n";
        while (prevCurr)
        {
            cout<<prevCurr->data<<" ";
            prevCurr = prevCurr->prev;
        }
        cout<<"\n\n";
    }

};


class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *pre = nullptr;
        Node *curr = head;
        while (curr)
        {
            Node *nextNode = curr->next;
            curr->next = pre;
            curr->prev = nextNode;
            pre = curr;
            curr = nextNode;
        }
        return pre;
    }
};

int main()
{
    cout << "Enter Size of DLL ";
    int n;
    cin >> n;
    cout << "Enter The dataue ";

    Node *head = nullptr;

    while (n--)
    {
        int data;
        cin >> data;
        head->insertNode(head, data);
    }


    head->printList(head);

    Solution obj;
    head = obj.reverseDLL(head);

    cout<<"\nAfter reverse\n";
    head->printList(head);

    /*  
        Output:
        
        Enter Size of DLL 6
        Enter The dataue 1 2 3 4 5 6
        6 5 4 3 2 1 
        1 2 3 4 5 6 

        After reverse
        1 2 3 4 5 6 
        6 5 4 3 2 1 
    */

    return 0;
}