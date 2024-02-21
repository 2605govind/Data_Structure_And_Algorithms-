#include<iostream>
#include<stack>
using namespace std;

void deleteMiddleElement(stack<int> &s ,int k) {
    // Base condition
    if(k == 1) {
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();

    deleteMiddleElement(s, k-1);

    s.push(val);
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

    // Even size
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);

    // Odd size
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int k = (s.size()/2+1);
    print(s);
    deleteMiddleElement(s , k);
    print(s);
}
