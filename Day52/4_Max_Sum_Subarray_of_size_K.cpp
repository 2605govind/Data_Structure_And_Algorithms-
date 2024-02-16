#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long sum = 0, mx = INT_MIN;
        int i = 0, j = 0;
        
        while(j < n) {
            sum += arr[j];
            // If k length sliding wondow not reach till then increment j
            if((j - i + 1) < k) {
                j++;

            // Every sliding window have execute else part    
            }else {
                mx = max(mx, sum);
                // Remove ith elemnet form window
                sum -= arr[i];
                j++; i++;
            }
        }
        
        return mx;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 


/* 1
    4 2
    100 200 300 400
    700
*/ 
