#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
 
    Node(int data, Node *prev = nullptr, Node *next = nullptr)
        : data(data), prev(prev), next(next) {}

    void insertNode(Node *&headNode, int data)
    {
        Node *newNode = new Node(data);
        if (!headNode)
            headNode = newNode;
        else{
            newNode->next = headNode;
            headNode->prev = newNode;
            headNode = newNode;
        }
    }
 
};

class Solution
{
public:

    int getMaximum(Node *headNode)
    {
        int maxElement = INT_MIN;
        while (headNode)
        {
            maxElement = max(maxElement, headNode->data);
            headNode = headNode->next;
        }
        return maxElement;
    }
};

int main()
{
    cout << "Enter Size ";
    int n;
    cin >> n;
    cout << "Enter Values ";
    Node *headNode = nullptr;

    while (n--)
    {
        int data;
        cin >> data;
        headNode->insertNode(headNode, data);
    }

    Solution obj;
    int maxElement = obj.getMaximum(headNode);
    cout << "\nThe maximum element is: " << maxElement;

    return 0;

    /*
        Output:

        Enter Size 6
        Enter Values 2 8 3 5 23 1 

        The maximum element is: 23
    */
}
