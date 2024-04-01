#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        int j = s.size() - 1 ;

        // remove and space
        while(j >= 0 && s[j] == ' ') {
            j--;
        }

        while(j >= 0) {
            if(s[j] == ' ') break;
            size++;
            j--;
        }
        
        return size;
    }
};

int main(){
    string s = "   fly me   to   the moon  ";

    Solution obj;
    cout<<obj.lengthOfLastWord(s);
}

/*
Input: s = "   fly me   to   the moon  "
Output: 4
*/
