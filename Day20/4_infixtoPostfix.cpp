#include <iostream>
#include <string.h>
#include <stdlib.h>
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
        char pop_val = s->arr[s->top];
        s->top--;
        return pop_val;
    }
}

bool isOpretor(char infix){
    if (infix == '+' || infix == '-')
    {
        return true;
    }

    if (infix == '*' || infix == '/')
    {
        return true;
    }
    return false;
    
}

int presi(char ch_pre){
    if (ch_pre == '+' || ch_pre == '-')
    {
        return 1;
    }

    if (ch_pre == '*' || ch_pre == '/')
    {
        return 2;
    }
    return 0;
}

char topMost(struct Stack *sp){
    return sp->arr[sp->top];
}

char* inToPost(char *infix, struct Stack *sp)
{

    char *postfix = (char *)malloc(sizeof(char) * strlen(infix));

    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOpretor(infix[i]))
        {
            postfix[j] = infix[i];
            i += 1;
            j += 1;
            
        }
        else
        {
            if (presi(infix[i]) > presi(topMost(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                // i++;
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
    
}

int main()
{   
    char *infix = "x+y*z-k";
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char) * strlen(infix));

    cout<<"the postfix is "<<inToPost(infix , sp);
  
    

    return 0;
}