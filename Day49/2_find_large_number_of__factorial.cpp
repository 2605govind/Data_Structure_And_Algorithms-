// Program for finding large number of factorial
#include<iostream>
using namespace std;

// Node
class Node {
public:
    int data;
    Node* next;

    Node(int x, Node* nxt = nullptr) {
        data = x;
        next = nxt;
    }
};

// Reverse Linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while(head) {
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}

void printList(Node* head) {
    while(head) {
        cout<<head->data;
        head = head->next;
    }
    cout<<"\n";
}

class Solution {
public:    
    // Method for deleting list
    void deleteList(Node* head) {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method for multiplication of two number where first repersent list and second is multiplier
    Node* multi(Node* fac, int multiplier) {
        // c store carry
        int carry = 0;

        Node* current = fac, *temp;
        while(current) {
            int val = current->data * multiplier + carry;
            current->data = val%10;
            carry = val / 10;

            temp = current;
            current = current->next; 
        }

        current = temp;
        while(carry) {
            current->next = new Node(carry%10);
            carry = carry/10;
        }

        return fac;
    }

    Node* findLargeNumberOfFac(int n) {
        Node* fac = new Node(1);
        for(int multiplier = 2; multiplier <= n; multiplier++) {
            fac = multi(fac, multiplier);
        }

        return fac;
    }
};



int main(){
    int n = 5;
    Solution s;
    Node* fac = s.findLargeNumberOfFac(n);
    fac = reverseList(fac);
    printList(fac);

    s.deleteList(fac);
}
