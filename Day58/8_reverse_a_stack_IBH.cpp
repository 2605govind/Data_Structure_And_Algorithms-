#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int temp) {
    if(s.size() == 0){
        s.push(temp);
        return;
    }

    int val = s.top(); s.pop();
    insert(s, temp);

    s.push(val);
}

void reverseStack(stack<int> &s) {
    // Base condition
    if(s.size() == 1) {
        return;
    }

    int temp = s.top();
    s.pop();

    reverseStack(s);

    insert(s, temp);
}

void print(stack<int> s) {
    // Base case
    if(s.size() == 0) {
        cout<<endl;
        return;
    }    

    // Induction
    cout<<s.top()<<" "; 
    s.pop();
    // Hypothesis
    print(s);
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    reverseStack(s);
    print(s);
}
