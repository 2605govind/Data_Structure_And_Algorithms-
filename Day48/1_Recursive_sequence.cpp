// Problem :- Recursive sequence
#include <bits/stdc++.h>
using namespace std;

// First solution using recursive way
class Solution{
    // Initialize mod for save integer out of bound
    const int MOD = 1e9 + 7;

    // Method for calculating sequence
    void fun(int n, int i, long long &start, long long &ans) {
        // Base case
        if(i > n) return;
        // Initialize 
        int move = i;
        long long add = 1;

        // F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15
        while(move--) {
            add = (add * start)%MOD;
            start++;
        }
        
        // Add in the 'ans'
        ans = (ans + add)%MOD;
        
        // Recursive call
        fun(n, i+1, start, ans);
    }
    
public:
    // Method for calling recursive
    long long sequence(int n){
        long long start = 1;
        long long ans = 0;
        
        // Call fun()
        fun(n, 1, start, ans);
        
        return ans;
    }
};

// Iterative solution
class Solution{
public:
    // Method for finding sequence
    long long sequence(int n){
        // Initialize mod for save integer out of bound
        int MOD = 1e9 + 7;
        // Initialize
        int i = 1;
        long long a = 1;
        long long ans = 0;
        // Iterate i is not equle to n
        while(i <= n) {
            int k = i;
            long long product = 1;
            // Every ith size multipy 'a' which is denoted = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 these numbers 
            while(k--) {
                product = (product%MOD * a)%MOD;
                a++;
            }
            
            // Add in ans and take modulo of MOD
            ans = (ans + product)%MOD;
    
            i++;
        }
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
