#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {

    // Function for converting word to morse code 
    string convertToMorse(string s) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int n = s.size();
        string str = "";

        // Iterate all charater from string
        for(int i = 0; i<n; i++) {
            char ch = s[i];

            // concatenation code based on letter from vector
            str += morse[ch-'a'];
        }

        // Return morse code of word
        return str;
    }

public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Count same transformattion
        unordered_map<string,int> mp;
        
        
        for(auto str : words) {

            // Using convertToMorse() function find morse codeof  string 
            mp[convertToMorse(str)]++;
        }

        // Map size repersent transformattion of words in morse code
        return mp.size();
    }
};

int main() {
    Solution sol;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << sol.uniqueMorseRepresentations(words) << endl; // Output: 2
    return 0;
}
