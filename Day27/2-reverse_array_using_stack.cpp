#include<iostream>
using namespace std;

struct Stack{
    int top;
    int *arra;
    int size;
};

void push(Stack *s ,int data){ 
    s->top++;
    s->arra[s->top] = data;
}

int pop(Stack *s){
    int data;
    data  = s->arra[s->top];
    s->top--;
    return data;
}

void dispay(Stack *s){
    for (int i = 0; i < s->size; i++)
    {
        cout<<s->arra[i]<<" ";
    }
    
}

void reverse_Array_Stack(Stack *s, int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        push(s, arr[i]);
        
    }
    arr = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = 4;
        // arr++;
        // cout<<pop(s)<<" ";
    }
    
}

// print complete array 
void print_Array(int A[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    
}

int main(){
    // implementation of stack
    struct Stack s;
    s.size = 5;
    s.arra = (int*)malloc(s.size * sizeof(int));
    s.top = -1;
    
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"befor Reverse an Array is ";
    print_Array(arr,size);

    cout<<"\nafter Reverse an Array is ";
    reverse_Array_Stack(&s,arr,size);
    // push(&s,4);
    // push(&s,5);
  
    // cout<<pop(&s);
    // cout<<pop(&s);
    // cout<<pop;
    // cout<<pop;
    print_Array(arr,size);
}