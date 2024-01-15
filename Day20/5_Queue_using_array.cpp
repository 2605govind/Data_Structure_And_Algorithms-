 #include <iostream>
using namespace std;

struct CircularQueue
{
    int size;
    int first;
    int back;
    int *arry;
};

int isFullQueue(struct CircularQueue *q)
{
    if ((q->back+1)%q->size == q->first)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmptyQueue(struct CircularQueue *q)
{
    if (q->first == q->back)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(struct CircularQueue *q, int value)
{
    if (isFullQueue(q))
    {
        cout << "Queue is overflow! " << endl;
    }
    else
    {   
        cout<<"Enqueue element is "<<value<<endl;
        q->back = (q->back+1)%q->size;
        q->arry[q->back] = value;
    }
}

int deQueue(struct CircularQueue *q)
{
    if (isEmptyQueue(q))
    {

        cout << "Queue is underflow! " << endl;
    }
    else
    {   
        
        int del_value = -1;
        q->first = (q->first+1)%q->size;
        del_value = q->arry[q->first];
        return del_value;
    }
}

void peekQueue(struct CircularQueue *q, int index)
{
    if (index >= q->first && index <= q->back)
    {
        cout << "index " << index << " at value is " << q->arry[index] << endl;
    }
    else
    {
        cout << "Invailid index value " << endl;
    }
}

int main()
{
    struct CircularQueue *qp = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    qp->size = 4;
    qp->back = 0;
    qp->first = 0;
    qp->arry = (int *)malloc(sizeof(int) * qp->size);

   
    

    enQueue(qp, 4);
    enQueue(qp, 6);
    enQueue(qp, 3);
    // if (isFullQueue(qp))
    // {
    //     cout << "Queue is full " << endl;
    // }
    // if (isEmptyQueue(qp))
    // {
    //     cout << "Queue is Empty " << endl;
    // }

    cout<<"dequeuing element "<<deQueue(qp)<<endl;
    cout<<"dequeuing element "<<deQueue(qp)<<endl;
    cout<<"dequeuing element "<<deQueue(qp)<<endl;
    // cout<<"dequeuing element "<<deQueue(qp)<<endl;
    
    enQueue(qp, 5);
    enQueue(qp, 9);
    enQueue(qp, 7);
    // enQueue(qp, 6);
 
    // cout<<"dequeuing element "<<deQueue(qp)<<endl;
    cout<<"dequeuing element "<<deQueue(qp)<<endl;
    cout<<"dequeuing element "<<deQueue(qp)<<endl;
    enQueue(qp, 7);
    // cout<<"dequeuing element "<<deQueue(qp)<<endl;
    // peekQueue(qp, 0);
    // peekQueue(qp, 1);
    // peekQueue(qp, 2);
    return 0;
}