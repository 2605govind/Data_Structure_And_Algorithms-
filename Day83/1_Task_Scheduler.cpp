#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x : tasks) {
            mp[x]++;
        }

        priority_queue<int> pq;
        for(auto x : mp) {
            pq.push(x.second);
        }

        int count = 0;

        while(!pq.empty()) {
            int temp = n+1;
            vector<int> left;

            while(temp--) {
                if(!pq.empty()) {
                    int val = pq.top();
                    pq.pop();
                    val--;
                    left.push_back(val);
                }
            }

            for(auto x : left) {
                if(x > 0) {
                    pq.push(x);
                }
            }

            if(pq.empty()) {
                count += left.size();
            }else {
                count += n+1;
            }
        }

        return count;
    }
};

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    Solution s;
    cout<<s.leastInterval(tasks, n);
}

/*
    Input: tasks = ["A","A","A","B","B","B"], n = 2

    Output: 8
*/
