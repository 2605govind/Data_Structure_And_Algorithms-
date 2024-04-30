//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        while (head)
        {
            Node *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node *dummy = new Node(0);
        Node *pointer = dummy;

        int carry = 0;
        while (num1 && num2)
        {
            int sum = num1->data + num2->data + carry;

            carry = sum / 10;
            sum = sum % 10;

            pointer->next = new Node(sum);
            pointer = pointer->next;

            num1 = num1->next;
            num2 = num2->next;
        }

        if (num1 == nullptr && num2 == nullptr)
        {
            pointer->next = new Node(carry);
        }

        while (num1)
        {
            int sum = num1->data + carry;

            carry = sum / 10;
            sum = sum % 10;
            pointer->next = new Node(sum);
            pointer = pointer->next;

            num1 = num1->next;
        }

        while (num2)
        {
            int sum = num2->data + carry;

            carry = sum / 10;
            sum = sum % 10;
            pointer->next = new Node(sum);
            pointer = pointer->next;

            num2 = num2->next;
        }

        pointer = reverseList(dummy->next);

        delete dummy;

        while (pointer->next)
        {
            if (pointer->data == 0)
            {
                Node *temp = pointer;
                pointer = pointer->next;
                delete temp;
            }
            else
            {
                break;
            }
        }

        return pointer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends