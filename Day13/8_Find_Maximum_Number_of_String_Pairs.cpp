#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> uset;

        for(auto s : words) {
            uset[s]++;
        }

        int count = 0;
        for(auto it : words) {
            string str = it;

            // 0 <= i < j < words.length here i very iterate remove from unordered map
            uset[str]--;

            // Reverse string
            reverse(str.begin(), str.end());

            // If reverse string is present in mp the count++
            if(uset[str]){
                count++;
            }

        }

        return count;
    }
};

int main(){
    vector<string> words = {"cd","ac","dc","ca","zz"};

    Solution s;
    cout<<s.maximumNumberOfStringPairs(words);
}
