#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(auto x : arr){
            mp[x]++;
        }

        unordered_set<int> uset;
        for(auto it : mp){
            if(!uset.count(it.second)){
                uset.insert(it.second);
            }else{
                return false;
            }
        }

        return true;
    }
};

int main(){
    
}
