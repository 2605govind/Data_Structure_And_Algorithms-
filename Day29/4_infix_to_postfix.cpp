#include<iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int x, Node* next = nullptr) : data(x), next(next) {}
};

// Stack template
class Stack {
    Node* peek;

public:
    int size;

    Stack(): peek(nullptr), size(0) {}

    bool isEmpty(){
        return peek == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val, peek);
        peek = newNode, size++;
    }

    int pop() {
        if(isEmpty()) return -1;
        Node* popNode = peek;
        peek = peek->next, size--;

        int val = popNode->data;
        delete popNode;
        return val;
    }

    int top(){
        if(isEmpty()) return -1;
        return peek->data;
    }
    
    void displayStack() {
        Node* curr = peek;
        std::cout<<"\n";
        while(curr) {
            std::cout<<curr->data<<" ";
            curr = curr->next;
        }
        std::cout<<"\n";
    }
};

int main() {

    /*
        Stack s;
        s.push(35);
        s.push(12);
        s.push(93);
        s.push(74);
        s.push(23);
        s.push(53);

        s.displayStack();
        std::cout<<s.size;

        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.displayStack();
        std::cout<<s.size;
    */

    return 0;
}