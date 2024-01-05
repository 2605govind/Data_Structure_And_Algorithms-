#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if(jewels.empty() || stones.empty()){
            return 0; // Handling edge case of empty strings
        }

        unordered_map<char,int> stonesFrequencyMap;

        // Counting occurrences of stones
        for(auto x : stones) {
            stonesFrequencyMap[x]++;
        }

        int jewelsCount = 0; 
        // Calculating count of jewels present in stones
        for(auto x : jewels) {
            jewelsCount += stonesFrequencyMap[x];
        }

        return jewelsCount;
    }
};

int main(){
    string jewels = "aA";
    string stones = "aAAbbbb";

    Solution s;
    cout<<s.numJewelsInStones(jewels, stones);
}
