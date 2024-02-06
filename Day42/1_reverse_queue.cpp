#include <iostream>
#include <queue>

class Solution {
public:
    void reverseQueue(std::queue<int> &q) {
        // Till queue is not empty all front store in recursive stack
        if(q.empty()) return;

        // Store front element
        int val = q.front();
        q.pop();
        reverseQueue(q);

        // Insert store element that repersent front of the q
        q.push(val);
    }

    void show(std::queue<int> q) {
        while(!q.empty()) {
            std::cout<<q.front()<<" ";
            q.pop();
        }
        std::cout<<"\n";
    }
};

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(50);

    Solution s;
    s.show(q);
    s.reverseQueue(q);
    s.show(q);


}