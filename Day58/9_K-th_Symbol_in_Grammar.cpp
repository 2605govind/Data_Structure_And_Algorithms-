#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) {
            return 0;
        }

        int mid = pow(2,n-1) / 2;

        if(k <= mid) {
            return kthGrammar(n-1, k);
        }else{
            return !kthGrammar(n-1, k-mid);
        }
    }
};

int main(){
    int n = 2;
    int k = 2;

    Solution s;
    cout<<s.kthGrammar(n,k);
}
