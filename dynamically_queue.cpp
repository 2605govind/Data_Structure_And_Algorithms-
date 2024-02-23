#include <iostream>
using namespace std;

struct Queue{
    int front, rear;
    int capacity;
    int *array;
};

struct Queue* createQueue(int cap){
    Queue *Q = new Queue;
    if(Q==NULL){
        cout<<"Queue not created ";
        return NULL;
    }else{
        Q->front = Q->rear = -1;
        Q->capacity = cap;
        Q->array = new int[Q->capacity];
        if(Q->array == NULL){
            return NULL;
        }
    }
    return Q;
}

int isFullQueue(Queue *q){
    return (((q->rear+1)%q->capacity)==q->front);
}

int isEmptyQueue(Queue *q){
    return (q->front == -1);
}

int queueSize(Queue *q){
    return ((q->capacity+q->front+q->rear+1)%q->capacity);
}

void enQueue(Queue *q,int data){
    if(isFullQueue(q)){
        cout<<"Queue is Overflow !";
    }else{
        q->rear = (q->rear+1)%q->capacity;
        q->array[q->rear] = data;
        if(q->front == -1){
            q->front = q->rear;
        }
    }
}

int deQueue(Queue *q){
    int data;
    if(isEmptyQueue(q)){
        cout<<"Queue is Underflow !";
        return -1;
    }else{
        data = q->array[q->front];
        if(q->front == q->rear){
            q->front = q->rear = -1;
        }else{
            q->front = (q->front+1)%q->capacity;
        }
    }
    return data;
}

int main(){
    Queue *newQ = createQueue(5);
    int n,num;
    while(1){
        cout<<"\n1 enQueue\n";
        cout<<"2 dnQueue\n";
        cout<<"3 exit\n";
        cin>>n;
        
        switch(n){
            case 1:
                cout<<"Enter a Number ";
                cin>>num;
                enQueue(newQ,num);
                break;
            case 2:
                cout<<"dequeue number is "<<deQueue(newQ);
                break;
            case 3:
                exit(0);
                break;
        }

    }
    return 0;
}