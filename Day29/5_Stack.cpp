#include<iostream>
using namespace std;

// Tamplate for creating dynamic array, incresing size in runtime
class DynamicArray {
    int capacity = 0;

    public:
    int* increaseSize(int *&a, int &n){
        // capacity incresing 2s power
        int size = 1<<capacity;
        capacity++;
        int* newArray = new int[size];

        if(a != nullptr) {
            int i = 0;
            for(; i < n; i++){
                newArray[i] = a[i];
            }

            while(i < size) {
                newArray[i] = 0;
                i++;
            }
            free(a);
        }
        n = size;
        return newArray;
    }
};

class Stack {
    int r;
    int* array = nullptr;
    int capacity = 0;
    DynamicArray dynamicArray;

    public: 
    Stack(int rear = -1) : r(rear)  {
        array = dynamicArray.increaseSize(array, capacity);
    }

    bool isEmpty() {
        if(r == -1) {
            return true;
        }else {
            return false;
        }
    }

    int size() {
        if(r == -1) return 0;
        return r;
    }

    void push(int val) {
        r++;
        if(r == capacity) {
            array = dynamicArray.increaseSize(array, capacity);
        }
        array[r] = val;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Underflow";
        }else{
            array[r] = 0;
            r--;
        }
    }

    void print() {
        for(int i = 0; i<=r; i++) {
            cout<<array[i]<<" ";
        }
    }
};

int main(){
    Stack s;

    s.push(32);
    s.push(75);
    s.push(75);
    s.push(99);
    s.push(99);
    s.push(99);
    s.push(99);
    s.push(99);

    s.print();
}
