#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> lowerHash(26, 0);

        for(auto x : sentence) {
            lowerHash[x - 'a'] = 1;
        }

        for(auto x : lowerHash) {
            if(x == 0) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    
}
