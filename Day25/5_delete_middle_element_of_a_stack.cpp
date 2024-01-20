#include<bits/stdc++.h>
using namespace std;

// delete element at middle index
void deletemid(stack<int> &s, int n, int i){
    // when we reach mid element then return
    if(i == n/2){
        s.pop();
        return;
    }
    // store s.top() for reach to mid element
    int value = s.top();
    s.pop();

    deletemid(s,n,i+1);
    // now mid element is delete and rest of the element just push in stack
    s.push(value);
}

// Print element
void printStack(stack<int> &s){
    // Itetare all stack element till stack became not empty
    if(s.empty()){
        cout<<endl;
        return;
    }
    int value = s.top();
    s.pop();
    printStack(s);

    cout<<value<<" ";
    s.push(value);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.push(50);

    // print Stack value
    printStack(s);

    int n = s.size();

    deletemid(s, n, 0);

    printStack(s);
}
