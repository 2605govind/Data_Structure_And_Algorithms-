#include<bits/stdc++.h>
using namespace std;


// for all nagive and positive
class Solution_1 {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0;
        int t = 0;
        for(auto x : nums) {
            int oo = ((~t) & o & (~x)) | ((~t) & (~o) & x);
            int tt = (t & (~o) & (~x)) | ((~t) & o & x);

            o = oo;
            t = tt;
        }

        return o;
    }
};


// for all positive
class Solution_2 {
  public:
    int singleElement(int arr[] ,int N) {
        int tn = INT_MAX, tnp1 = 0, tnp2 = 0;
        
        for(int i = 0; i < N; i++) {
            int cwtn = arr[i] & tn;
            int cwtnp1 = arr[i] & tnp1;
            int cwtnp2 = arr[i] & tnp2;
            
            tn = tn & (~cwtn);
            tnp1 = tnp1 | cwtn;
            
            tnp1 = tnp1 & (~cwtnp1);
            tnp2 = tnp2 | (cwtnp1);
            
            tnp2 = tnp2 & (~cwtnp2);
            tn = tn  | cwtnp2;
        }
        
        return tnp1;
    }
};

int main(){
    
}
