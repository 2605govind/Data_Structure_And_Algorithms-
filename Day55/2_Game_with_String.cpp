#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        // Storing occurence of character int string s
        unordered_map<char,int> mp;
        
        for(auto x : s) {
            mp[x]++;
        }
        
        // Create max heap
        priority_queue<int> pq;
        
        // Insert all occrences based on priority 
        for(auto x : mp) {
            pq.push(x.second);
        }
        
        // Remove k occurence form max charater occurence
        while(k--) {
            int val = pq.top();
            pq.pop();
            val--;
            pq.push(val);
        }
        
        // Now calculate squares of occurences
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top() * pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}

/*
    Input:
    1
    aabcbcbcabcc
    3

    Output:
    27
*/