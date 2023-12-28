#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        while(n) {
            int bsm = n & - n;
            count++;
            n -= bsm;
        }

        return count;
    }
};

int main(){
    Solution s;

    uint32_t n = 3;

    cout<<s.hammingWeight(n);
}
