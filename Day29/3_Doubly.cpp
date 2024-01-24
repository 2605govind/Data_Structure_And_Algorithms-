#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* createDoublyList(){
    int n;
    cin>>n;
    int num;
    Node* nxt = NULL;
    while(n--) {
        cin>>num;
        Node* newNode = new Node(num);

        newNode->next = nxt;
        nxt = newNode;
    }

    Node* pre = NULL;
    Node* head = nxt;
    Node* curr = nxt;
    while(curr) {
        curr->prev = pre;
        pre = curr;

        curr = curr->next;
    }
    cout<<"\n";
    return head;
}

void print(Node* head) {
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        if(curr->next){
            curr  = curr->next;
        }else{
            break;
        }
    }
    cout<<endl;
    while(curr){
        cout<<curr->data<<" ";
        curr  = curr->prev;
    }
}

int main(){
    Node* head = createDoublyList();

    print(head);
}
