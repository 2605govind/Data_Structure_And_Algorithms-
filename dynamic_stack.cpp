#include <iostream>
using namespace std;

// basic template for Stack DSA
struct Stack{
    int top;
    int capacity;
    int *Array;
};

bool isFull(Stack *s){
    if(s->top == (s->capacity-1)){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(Stack *s){
    if(s->top == -1){
        return true;
    }else{
        return false;
    }
}

struct Stack* createStack(int cap){
    Stack *stack1 = new Stack;
    stack1->top = -1;
    stack1->capacity = cap;
    stack1->Array = new int[stack1->capacity];
    return(stack1);
}

// push operation of Stack
void push(Stack *s, int data){
    if(isFull(s)){
        cout<<"Stack is Overflow !"<<endl;
        
    }else{
        s->top = s->top + 1;
        s->Array[s->top] = data;
        // cout<<data<<" pushed "<<endl;
    }
}

// pop operation of Stack
int pop(Stack *s){
    int delete_data;
    if(isEmpty(s)){
        cout<<"Stack is Underflow !"<<endl;
       
    }else{
        delete_data = s->Array[s->top];
        s->top = s->top - 1;
        // cout<<delete_data<<" poped "<<endl;
    }
    return delete_data;
}

int main(){
    int choise, data, pop_data;
    Stack *stack1 = createStack(5);

    while(1){
        cout<<"\n 1 push ";
        cout<<"\n 2 pop ";
        cout<<"\n 3 exit ";
        cin>>choise;
    
        switch(choise){
            case 1:
                if(isFull(stack1)){
                    cout<<"stack is full ";
                }else{
                    cout<<"Enter number ";
                    cin>>data;
                    push(stack1,data);
                }
                break;
            case 2:
                if(isEmpty(stack1)){
                    cout<<"stack is Empt ";
                }else{
                    pop_data = pop(stack1);
                    cout<<"pop value is "<<pop_data;
                }
                break;
            case 3:    
                exit(0);    
        }
    }
    return 0;
}