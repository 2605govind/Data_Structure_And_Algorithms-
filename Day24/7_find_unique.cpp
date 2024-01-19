#include <unordered_map>
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
    int getNodeWithoutDuplicates(Node *head)
    {
        if (!head || !head->next)
            return head->data;
        unordered_map<int, int> freq;
        while (head)
        {
            freq[head->data]++;
            head = head->next;
        }
        for (auto p : freq)
        {
            int nodeData = p.first;
            int count = p.second;
            if (count == 1)
                return nodeData;
        }
        return -1;
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

    head->printList(head);

    Solution obj;
    int uniqData = obj.getNodeWithoutDuplicates(head);
    cout <<"\n"<<uniqData << " is the node without duplicates ";
                                                         
    return 0;

    /*
        output:
        Enter Size 8
        Enter Values 1 2 2 3 5 4 6 9
        9 6 4 5 3 2 2 1 
        1 2 2 3 5 4 6 9 
        
        
        1 is the node without duplicates
    */
}