#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};


Node* insert(Node* head, int value, int pos) {
    Node* newNode = new Node(value);
    if(pos == 0) {
        newNode->next = head;
        return newNode;
    }
    
    Node* curr = head;
    pos--;
    while(curr && pos--) {
       curr = curr->next;
    }
    
    if(curr == nullptr) return head; 
    newNode->next = curr->next;
    curr->next = newNode;
    
    return head;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    while(head){
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

void print(Node* head) {
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Node *head = nullptr;
    int n = 7;
    while(n--){
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    int value, pos;
    cin>>pos>>value;
    head = reverse(head);
    // print(head);
    
    head = insert(head, value, pos);
    print(head);
    
    return 0;
}
