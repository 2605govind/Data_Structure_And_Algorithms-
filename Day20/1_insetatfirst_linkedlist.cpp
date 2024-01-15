#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return *ptr;
}

void insertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

void insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

void insertAfterNode(struct Node *pre_node, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = pre_node->next;
    pre_node->next = ptr;
}

void displayLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head, *second, *third;
    // insertLikedList(head , 8434 , second);
    // insertLikedList(second , 2 , third);
    // insertLikedList(third , 7 , NULL);

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 54;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 65;
    third->next = NULL;

    cout << "your linked list is " << endl;
    displayLinkedList(head);

    // cout << "After insert Element at any index " << endl;
    // insertAtIndex(head, 745, 1);
    // insertAtIndex(head, 235, 2);
    // insertAtIndex(head, 45, 3);
    // insertAtIndex(head, 5, 4);
    // insertAtIndex(head, 25, 5);
    // displayLinkedList(head);

    cout<<"After insert Element at end "<<endl;
    insertAtLast(head,69);
    insertAtLast(head,9);
    displayLinkedList(head);

    // cout<<"After insert Element in first "<<endl;
    // struct Node ptr = insertAtFirst(head, 92);
    // displayLinkedList(&ptr);

    cout<<"After insert Element at Node "<<endl;
    insertAfterNode(second,9999);
    displayLinkedList(head);

    return 0;
}