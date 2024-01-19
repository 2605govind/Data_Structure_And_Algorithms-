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
    Node *reverseKth(Node *head, int k)
    {
        if (!head || !head->next || k <= 0)
            return head;
        Node *resHead = nullptr, *rescurr = nullptr;
        stack<Node *> s;
        while (head)
        {
            for (int node = 1; node <= k && head; ++node)
            {
                s.push(head);
                head = head->next;
            }
            while (!s.empty())
            {
                Node *temp = s.top();
                s.pop();
                if (!resHead)
                    resHead = temp, rescurr = temp;
                else
                    rescurr->next = temp, rescurr = rescurr->next;
            }
        }
        rescurr->next = nullptr;
        return resHead;
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

    cout << "\nList before reverse \n";
    head->printList(head);
    int k;
    cout << "\nEnter k ";
    cin >> k;

    Solution obj;
    head = obj.reverseKth(head, k);

    cout << "\nList after reverse \n";
    head->printList(head);

    return 0;


    /*
        Output:
        
        Enter Size 9
        Enter values 1 2 3 4 5 6 7 8 9
        
        List before reverse 
        9 8 7 6 5 4 3 2 1   
        1 2 3 4 5 6 7 8 9   
        
        
        Enter k 4
        
        List after reverse
        6 7 8 9 2 3 4 5 1
        1 2 3 4 5 6 7 8 9
    */
}