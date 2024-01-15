#include <iostream>
#include <string.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *arr;
};

bool isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    return false;
}

void push(struct Stack *s, char push_char)
{
    if (isFull(s))
    {
        cout << "stack is overflow! " << endl;
    }
    else
    {
        s->top += 1;
        // cout<<"\n"<<s->top;
        s->arr[s->top] = push_char;
    }
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        cout << "stack is underflow! " << endl;
    }
    else
    {
        int pop_val = s->arr[s->top];
        s->top--;
        return pop_val;
    }
}

bool match(char a , char b){
    if (a == '{' && b=='}')
    {
        return true;
    }
    if (a == '(' && b==')')
    {
        return true;
    }
    if (a == '[' && b==']')
    {
        return true;
    }
    return false;
    
}

char topMost(struct Stack *s){
    return s->arr[s->top];
}

bool parenthesisMatch(char *pare_arr, struct Stack *p){
    char popped_ch;
    
     for (int i = 0; i < pare_arr[i] != '\0'; i++)
    {
        if (pare_arr[i] == '(' ||pare_arr[i] == '{'||pare_arr[i] == '[')
        {
            push(p, pare_arr[i]);
        }
        if (pare_arr[i] == ')' ||pare_arr[i] == '}'||pare_arr[i] == ']')
        {            
            if (isEmpty(p))
            {
                return false;
            }
            
           popped_ch = pop(p);
           if (!match(popped_ch,pare_arr[i]))
           {
                return 0;
           }
           

        }
    }

    if (isEmpty(p))
    {
        return true;
    }
    else
    {    
        return false;
    }
   
}

int main()
{
    char *pare_arr = "[32][({3+4})]";
    int size =0;
    while (pare_arr[size] != '\0')
    {  
        size++;
    }   
    // int s = strlen(pare_arr);
    // cout<<s;
    struct Stack *p = (struct Stack*)malloc(sizeof(struct Stack));
    p->top = -1;
    p->size = 10;
    p->arr = (char*)malloc(sizeof(char)*p->size);

    bool ismatch = parenthesisMatch(pare_arr , p);

    // free(p->arr);
    if (ismatch)
    {
        cout<<"parenthesis is matching ";
    }else{
        cout<<"parenthesis is not matching ";

    }
    

    return 0;
}