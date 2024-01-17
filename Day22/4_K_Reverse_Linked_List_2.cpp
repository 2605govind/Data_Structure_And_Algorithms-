#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};


Node* reverse(Node* head){
    Node* prev = nullptr;    
    while(head ){
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

Node* kthRE(Node* head, int k) {
    stack<Node*> s;
    Node* dummyN = new Node(0);
    Node* dummyNode = dummyN;
    Node* curr = head;
    
    while(curr){
        if((int)s.size() != k){
            s.push(curr);
            curr = curr->next;
        }else{
            while(!s.empty()){
                dummyNode->next = s.top();
                s.pop();
                dummyNode = dummyNode->next;
            }
        }
        
        
    }
    
    while(!s.empty()){
        dummyNode->next = s.top();
        s.pop();
        dummyNode = dummyNode->next;
    }
    
    dummyNode->next = nullptr;
    
    
    return dummyN->next;
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
    int n;
    while(cin>>n){
        if(n == -1) break;
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }
        
    int k;
    cin>>k;
    head = reverse(head);
    if(k == 0) {
        print(head);
        return 0;
    }
    // print(head);
    head = kthRE(head, k);
    print(head);
    return 0;
}
