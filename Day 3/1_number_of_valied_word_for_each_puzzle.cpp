#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    vector<int> findNumOfValidWords(vector<string> &puzzle, vector<string> &words) {
        // make a to z hashmap and every ith contain a vector of integer
        vector<vector<int>> hashMap (26);

        int n = words.size();
        for(int i = 0; i < n; i++) {
            int mask = 0;
            string str = words[i];

            for(int j = 0; j < str.size(); j++) {
                mask = mask | (1 << (str[j] - 'a') );
            }


            unordered_set<int> s;
            for(int j = 0; j < str.size(); j++) {
                if(s.count(mask)) {
                    continue;
                }   
                s.insert(mask);
                hashMap[str[j] - 'a'].push_back(mask);
            }
        }

        vector<int> ans;
        int puzSize = puzzle.size();
        for(int i = 0; i < puzSize; i++) {
            string str = puzzle[i];

            int mask = 0;
            for(int j = 0; j<str.size(); j++) {
                mask = mask | 1<<(str[j] - 'a');
            }

            int val = str[0] - 'a';
            int size = hashMap[val].size();

            int count = 0;
            for(int j = 0; j<size; j++) {   
                int wmask = hashMap[val][j];

                if((wmask & mask) == wmask) {
                    count++;
                }
            }

            ans.push_back(count);
            
        }

        return ans;
    }
};


int main(){
    /*
    Problem is :
    given puzzle and words in lowercase and you have to find for each puzzle how many number of words
    whose all charactors are available(valid words) in puzzle then count this word. do it for every puzzle for every words
    and then print;
    */
    vector<string> puzzle = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    vector<string> words = {"aaaa", "asas", "able", "ability", "actt", "actor","access"};
    
    Solution s1;

    vector<int> vec = s1.findNumOfValidWords(puzzle, words);

    int n = vec.size();
    for(int i = 0; i < n; i++) {
        cout<<vec[i]<<endl;
    }

}
