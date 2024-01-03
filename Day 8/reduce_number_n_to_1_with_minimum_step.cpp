#include<iostream>
using namespace std;

class Solution {
    public:

    int reduceNumberWithMinimumStep(int n) {
        int res = 0;

        while(n != 1) {
            if(n%2 == 0) {
                n = n/2;
            } else if(n == 3) {
                n = n-1;
                break;
            } else if(n&3 == 1) {
                n = n-1;    
            } else if(n&3 == 3) {
                n = n+1;
            }
            res++;
        }

        return res;
    }
};

int main(){
    int n = 15;

    Solution s;
    cout<<s.reduceNumberWithMinimumStep(n);

    // n = n>>10;

    // cout<<n;
}
