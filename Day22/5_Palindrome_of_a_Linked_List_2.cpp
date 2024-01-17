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

bool checkPalindron(Node* head) {
    Node* first = head;
    Node* second = head->next;
    
    while(second && second->next){
        first = first->next;
        second = second->next->next;
    }
    
    first->next = reverse(first->next);
    
    // cout<<first->next->data<<"   "<<head->data;
    second = first->next;
    first = head;
    
    
    while(second && first){
        if(second->data != first->data) {
            return false;
        }
            
        first = first->next;
        second = second->next;
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Node *head = nullptr;
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
        
    head = reverse(head);
    // checkPalindron(head);
      
    if(checkPalindron(head)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    
    return 0;
}
