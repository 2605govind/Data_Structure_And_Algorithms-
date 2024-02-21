#include<iostream>
#include<stack>
using namespace std;

void deleteMiddleElement(stack<int> &s) {
    // Base condition
    if(s.size() == 0) {
        return;
    }

    int val = s.top();
    s.pop();

    deleteMiddleElement(s);

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

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    deleteMiddleElement(s);
    print(s);
}
