#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{


};

    node* rev(node *head){
        node* prev = NULL;
        node* curr = head;
        
        while(head){
            head = head->next;
            curr->next = prev;
            
            prev = curr;
            curr = head;
        }
        
        return prev;
    }
  
    // void *reverse (struct node *head, int k)
    // { 
    //     head = rev(head);
        
      
    //     // return prev;
        
    // }

void print(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}    

int main(){
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    print(head);
    head = rev(head);
    print(head);


    
}
