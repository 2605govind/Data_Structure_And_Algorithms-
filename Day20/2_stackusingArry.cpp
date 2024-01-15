#include <iostream>
#include <stdlib.h>
using namespace std;

// basic implement of stact using array
struct stack
{
    int size;
    int top;
    int *arr;
};

// it fuction is check stack is full or not
int isFull(struct stack *s)
{
    if ((s->size - 1) == s->top)
    {
        return 1;
    }
    return 0;
}

// it fuction is check stact is empty or not
int isEmpty(struct stack *s)
{
    if (-1 == s->top)
    {
        return 1;
    }
    return 0;
}

// push function is operation of stack whitch add new value in stack
void pushStack(struct stack *s, int value)
{
    if (isFull(s))
    {
        cout << "\nstack is owerflow! can not push "<<value<<" to the stack \n";
    }
    else
    {
        s->arr[s->top += 1] = value;
    }
}

// pop function the remove top of element in stack
int popStack(struct stack *s)
{
    if (isEmpty(s))
    {
        cout << "\nstack is Empty ! \n";
    }
    else
    {   
        int val = s->arr[s->top];
        s->top--;
        s->arr[s->top];
        return val;
    }
}

int peekStack(struct stack *s , int pos){
    if (s->top+1-pos < 0)
    {
        cout<<"Not a valid position! "<<endl;
        return -1;
    }else{
        return s->arr[s->top+1-pos];
    }
    
}

int topStack(struct stack *s){
    return s->arr[s->top];
}

int bottomStack(struct stack *s){
    return s->arr[s->top-s->top];
}

// display stack
void dispayStack(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << "indext " << i << " at value is " << s->arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    // create instant of stack s
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 6; // maximum size of stack is size
    s->top = -1;
    // using dynamicaly memory resuv in heap
    s->arr = (int *)malloc(s->size * sizeof(int));

    // function call
    pushStack(s, 2);
    pushStack(s, 6);
    pushStack(s, 8);
    pushStack(s, 9);

    dispayStack(s);

    // cout<<"pop the value is "<<popStack(s)<<endl;
    // cout<<"pop the value is "<<popStack(s)<<endl;
    // cout<<"pop the value is "<<popStack(s)<<endl;

    cout<<"At position 3 value is "<<peekStack(s,3)<<endl;
    cout<<"top value is "<<topStack(s)<<endl;
    cout<<"bottom value is "<<bottomStack(s)<<endl;
    return 0;
}