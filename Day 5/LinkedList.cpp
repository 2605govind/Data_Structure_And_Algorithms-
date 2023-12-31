#include<iostream>
using namespace std;

// basic node template
struct node
{
    int data;
    node *next;
};


// this function using for creating node and next point to null
node* createNode(int data){
    node* n = new node; // allocation in dynamically
    n->data = data;
    n->next = NULL;
    return n;
}

// Traversing function for list
void printList(node *head){
    while (head != NULL){
        cout<<head->data<<" ";
        head =head->next;
    }cout<<endl;    
}

int listSize(node *head){
    int count = 0;
    while (head != NULL){
        count++;
        head =head->next;
    } 
    return count;
}

// insetion function-------------------------------
node* insertionAtFront(node* head, int data){
    node* temp = createNode(data);
    if(temp == NULL){
        return head;
    }
    else{
        temp->next = head;
        return temp;
    }
    
}

node* insertionAtMiddle(node* head, int data, int pos){
    node* temp = createNode(data);
    if(temp == NULL){
        return head;
    }else{
        node* prev;
        node* cur = head;
        int i = 1;
        if(pos > listSize(head)){
          cout<<"position is not vailid\n" ;
          return head;  
        } 
        while (i < pos)
        {
            i++;
            prev = cur;
            cur = cur->next;
        }
        prev->next = temp;
        temp->next = cur;
        }
    return head;
}

node* insertionAtEnd(node* head, int data){
    node* temp = createNode(data);    
    if(temp == NULL){
        return head;
    }else{
        node* n;
        while (n->next != NULL){
            n =n->next;
        } 
        n->next = temp;
    }
    return head;
}

// deletion function-------------------------------
node* deleteAtFront(node* head){
    if(head == NULL){
        return head;
    }else{
        int data = head->data;
        node* temp = head;
        cout<<"delete front element "<<data<<endl;
        head = head->next;
        free(temp);
    }
    return head;
}

node* deleteAtMiddle(node* head, int pos){
    if(head == NULL){
        return head;
    }else{
        node* prev;
        node* cur = head;
        int i = 1;

        if(pos > listSize(head)){
          cout<<"position is not vailid\n" ;
          return head;  
        } 
        while (i < pos)
        {
            i++;
            prev = cur;
            cur = cur->next;
        }
        node* temp = cur;
        cur = cur->next;
        prev->next = cur;
        cout<<"delete at pos "<<pos<<" form middle element "<<temp->data<<endl;
        free(temp);
    }
    
    return head;
}

node* deleteAtEnd(node* head){
    node* n;
    node* cur=head;
    n = n->next;
    while (n->next != NULL){
        n =n->next;
        cur = cur->next;
    } 
    cur->next = NULL;
    cout<<"delete end element "<<n->data<<endl;
    free(n);
    return head;
}

int main(){
    // creating a LInked List;
    node* head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(8);

    // print List 
    printList(head);

    // size of list
    cout<<"size of list is "<<listSize(head)<<endl;

    // insertion function
    // insert at front
    head = insertionAtFront(head, 9);
    printList(head);

    // insert at middle
    head = insertionAtMiddle(head,32, 4);
    printList(head);

    // insert at End
    head = insertionAtEnd(head,68);
    printList(head);

    // detetion function
    // detete at front
    head = deleteAtFront(head);
    printList(head);

    // detete at middle
    head = deleteAtMiddle(head,2);
    printList(head);

    // detete at End
    head = deleteAtEnd(head);
    printList(head);

    return 0;
}