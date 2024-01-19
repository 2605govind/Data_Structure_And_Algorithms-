#include <iostream>
#include <vector>
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
     Node *insertAtPos(Node *head, int position, int posData)
    {
        if (!head)
            return new Node(posData);
        if (position <= 1)
        {
            Node *newNode = new Node(posData);
            newNode->next = head;
            return newNode;
        }
        vector<Node *> container;
        Node *curr = head, *nodeLast = nullptr;
        int i = 1;
        while (curr)
        {
            if (i == position)
                container.push_back(new Node(posData));
            container.push_back(curr);
            nodeLast = curr;
            curr = curr->next;
            i++;
        }
        int size = container.size();
        if (position >= size)
        {
            Node *newNode = new Node(posData);
            nodeLast->next = newNode;
            newNode->prev = nodeLast;
            return head;
        }
        for (int node = 0; node < size; ++node)
        {
            if (node > 0)
                container[node]->prev = container[node - 1];
            if (node < size)
                container[node]->next = container[node + 1];
        }
        container[0]->prev = nullptr;
        container[size - 1]->next = nullptr;
        return container[0];
    }
};


int main()
{
    cout << "Enter size ";
    int n;
    cin >> n;
    cout << "Enter value ";

    Node *head = nullptr;

    while (n--)
    {
        int data;
        cin >> data;
        head->insertNode(head, data);
    }
    int posData, position;
    cout << "Enter data and position ";
    cin >> posData >> position;

    cout << "\nList before insertion: \n";
    head->printList(head);

    Solution obj;
    head = obj.insertAtPos(head, position, posData);

    cout << "\nList after insertion: \n";
    head->printList(head);


    /*
        output 1:
        Enter size 8
        Enter value 1 2 3 4 5 6 7 8 
        Enter data and position 43 1

        List before insertion: 
        8 7 6 5 4 3 2 1        
        1 2 3 4 5 6 7 8        

        List after insertion:
        43 8 7 6 5 4 3 2 1
        1 2 3 4 5 6 7 8

        output 2:
        Enter size 6
        Enter value 5 2 3 7 4 5
        Enter data and position 434 5

        List before insertion: 
        5 4 7 3 2 5 
        5 2 3 7 4 5 

        List after insertion:
        5 4 7     3  434 2 5
        5 2 434  3   7    4 5
    */
    return 0;
}