#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
    public:
    // function for build linked list using array
    Node* buildLinkedList(int array[], int size) {
        // make head node and storing array first element
        Node* head = new Node(array[0]);
        Node* curr = head;

        // here iterate all elements of array and make node and conecting 
        for(int i=1; i<size; i++) {
            curr->next = new Node(array[i]);
            curr = curr->next;
        }

        return head;
    }

    // function for printing all list elements
    void print(Node* head){
        while(head) {
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<"\n";
    }
};


class Solution1 {
    public:
    Node* mergeNodes(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* dummy = dummyNode;

        int zero = 0, sum = 0;
        Node* curr = head;

        while(curr) {
            sum += curr->data;
            if(curr->data == 0) {
                dummy->next = new Node(sum);
                dummy = dummy->next;
                sum = 0;
            }

            Node*temp = curr;
            curr =curr->next;

            delete temp;
        }

        dummy->next = NULL;
        head = dummyNode->next;

        delete dummyNode;

        return head->next;
    }
};

int main() {
    // here t is number of test cases
    int t;
    cin>>t;

    // here iterate it, number of test case
    while(t--) {
        int size;
        cin>>size;
        // here storing elements 
        int *array = new int(size);

        for(int i=0; i<size; i++) {
            cin>>array[i];
        }

        delete array;

        LinkedList* linkedlist = new LinkedList();
        Solution1 *s1 = new Solution1();

        // here convert Array to Linked List
        Node* head = linkedlist->buildLinkedList(array, size);
        
        Node* ans = s1->mergeNodes(head);
        linkedlist->print(ans);
    }

    /*
    1
    10
    0 1 5 3 0 0 3 4 5 0
    */
    return 0;
}