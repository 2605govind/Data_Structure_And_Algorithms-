#include <iostream>
#include <stack>
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
    bool isPalindrome(Node *head)
    {
        if (!head || !head->next)
            return true;
        Node *curr = head;
        stack<int> s;
        while (curr)
        {
            s.push(curr->data);
            curr = curr->next;
        }
        while (!s.empty())
        {
            if (head->data != s.top())
                return false;
            head = head->next;
            s.pop();
        }
        return true;
    }
};

int main()
{
    cout << "Enter Size ";
    int n;
    cin >> n;
    cout << "Enter values ";

    Node *head = nullptr;
    while (n--)
    {
        int data;
        cin >> data;
        head->insertNode(head, data);
    }

    head->printList(head);
    Solution obj;
    if (obj.isPalindrome(head))
        cout << "\ndoubly linked list is a palindrome!";
    else
        cout << "\ndoubly linked list is not a palindrome!";

    /*
        Output:
        
        Enter Size 7
        Enter values 1 2 3 4 3 2 1
        1 2 3 4 3 2 1 
        1 2 3 4 3 2 1 

        doubly linked list is a palindrome!
    */    

    return 0;
}