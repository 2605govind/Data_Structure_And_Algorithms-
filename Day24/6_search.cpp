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
    bool searchNode(Node *head, int searchData)
    {
        if (!head)
            return false;
        while (head)
        {
            if (head->data == searchData)
                return true;
            head = head->next;
        }
        return false;
    }
};

int main()
{
    cout << "Enter Size ";
    int n;
    cin >> n;
    cout << "Enter Values ";

    Node *head = nullptr;
    while (n--)
    {
        int data;
        cin >> data;
        head->insertNode(head, data);
    }
    int searchData;
    cout << "Enter data for search: ";
    cin >> searchData;

    cout << "\nList: \n";
    head->printList(head);
    Solution obj;
    if (obj.searchNode(head, searchData))
        cout << "\nData " << searchData << " is present in the list";
    else
        cout << "\nData " << searchData << " is not present in the list";


    /*
        Output:
        
        Enter Size 7
        Enter Values 3 2 5 9 34 22 49
        Enter data for search: 9

        List: 
        49 22 34 9 5 2 3 
        3 2 5 9 34 22 49 

        Data 9 is present in the list
    */
    return 0;
}