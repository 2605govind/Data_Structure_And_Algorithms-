#include<iostream>
#include<stack>
using namespace std;

// Method for inserting element at right place
void insert(stack<int> &s, int temp) {
    // Base condition
    if(s.size() == 0 || s.top() <= temp ) {
        s.push(temp);
        return;
    }

    // Induction
    int val = s.top();
    s.pop();

    insert(s, temp);
    s.push(val);
}

// Method for sorting a stack
void sort(stack<int> &s) {
    // Base case
    if(s.size() == 1) {
        return;
    }

    // Induction
    int temp = s.top();
    s.pop();

    // Hypothesis
    sort(s);

    insert(s, temp);
}

// Method for printing elements
void print(stack<int> s) {
    if(s.size() == 0) return;
    int val = s.top();
    s.pop();
    print(s);
    cout<<val<<" ";

    return;
}

int main(){
    // Insert value in stack
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(9);
    s.push(-2);
    s.push(4);

    // Sorting method call
    sort(s);

    // Print stack
    print(s);
}
