#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;

        for(int i = 0; i < 32; i++) {
            int submask = 0;
            submask = 1<<i;
            
            if(n & submask) {
                (i%2 == 0) ? even++ : odd++;
            }
        }

        return {even, odd};
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<int> vec = s.evenOddBit(n);

    cout<<vec[0]<<" "<<vec[1];
}
