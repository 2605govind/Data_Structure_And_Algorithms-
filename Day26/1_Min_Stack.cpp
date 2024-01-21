#include<iostream>
using namespace std;

class MinStack {
    int mini = INT_MAX;
    stack<pair<int,int>> s;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push({val, mini});
        mini = min(mini, val);
    }
    
    void pop() {
        if(s.size() == 0) return;

        mini = s.top().second;
        s.pop();
    }
    
    int top() {
        if(s.size() == 0){
            return -1;
        }

        return s.top().first;
    }
    
    int getMin() {
        return mini;
    }
};

int main(){
    
}
