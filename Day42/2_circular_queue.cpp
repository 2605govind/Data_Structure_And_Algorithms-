#include <iostream>
using namespace std;

class Queue {
    int rear, front;
    int size;   
    int *array;

public:
    Queue(int s) {
        rear = front = -1;
        size = s;
        array = new int[s];
    }

    void enqueue(int x);
    int dequeue();
    void display();

    ~Queue() {
        delete[] array;
    }
};


void Queue::enqueue(int x) {
    if(front == 0 && rear == size-1 || (rear+1)%size == front ){
        cout<<"Insertino Error! Queue is full\n";
        return;

    }else if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        array[rear] = x;

    }else if(rear == size-1 && front != 0) {
        rear = 0;
        array[rear] = x;
        
    }else {
        rear++;
        array[rear] = x;
    }
}

int Queue::dequeue() {
    if(front == -1) {
        cout<<"Deletion Error! dequeue is empty\n";
        return -123456;

    } else if(front == rear) {
        int x = array[front];
        front = rear = -1;
        return x;

    } else if(front == size-1) {
        int x = array[front];
        array[front] = -1;
        front = 0;
        return x;

    }else {
        int x = array[front];
        array[front] = -1;
        front++;
        return x;
    }
}

void Queue::display() {
    for(int i = 0; i < size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}


int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<endl;
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<endl;
    q.enqueue(5);

    q.display();

}