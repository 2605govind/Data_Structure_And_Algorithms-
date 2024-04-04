#include<iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = 0;

        for(char x : s) {
            if(x == '(') {
                count++;
            } else if(x == ')'){
                count--;
            }
            ans = max(ans, count);
        }

        return ans;
    }

};

int main(){
    string s = "(1+(2*3)+((8)/4))+1";

    Solution obj;
    cout<<obj.maxDepth(s);
}
