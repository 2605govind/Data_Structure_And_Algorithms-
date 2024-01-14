#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> array1(26);
        vector<int> array2(26);

        for(auto s : word1){
            array1[s-'a']++;
        }

        for(auto s : word2){
            array2[s-'a']++;
        }

        for(int i = 0; i<26; i++) {

            bool countArray1 = array1[i] > 0;
            bool countArray2 = array2[i] > 0;

            if((countArray1 && !countArray2) || (!countArray1 && countArray2) ){
                return false;
            }
        }

        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        for(int i = 0; i<26; i++){
            if(array1[i] != array2[i]){
                return false;
            }
        }

        return true;
    }
};


int main(){
    Solution s;
    string word1 = "abc";
    string word2 = "cba";

    cout<<s.closeStrings(word1,word2);
}
