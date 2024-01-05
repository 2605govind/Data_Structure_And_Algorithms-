#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        if(order.empty() || s.empty()) {
            return "" ; // Handling edge case for emtpy string
        }

        unordered_map<char,int> charFrequencyMap;

        // Counting occurrences of s
        for(auto x : s) {
            charFrequencyMap[x]++;
        }

        string customSortString = "";

        // Itetate order string for making oderString based on occurrences of s
        for(auto x : order) {
            while(charFrequencyMap[x] > 0) {
                customSortString.push_back(x);
                charFrequencyMap[x]--;
            }
            charFrequencyMap.erase(x);
        }

        // Left Occurrence insering in string with "s" order
        for(auto x : charFrequencyMap) {
            while(x.second > 0) {
                customSortString.push_back(x.first);
                x.second--;
            }
        }

        return customSortString;
    }
};

int main(){
    string order= "abc";
    string s= "addgbcbbsc";

    Solution solution;
    cout<<solution.customSortString(order, s);
}
