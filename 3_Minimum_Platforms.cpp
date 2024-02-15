// Program to find minimum number of platforms required on a railway station
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Sort bath the array
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        // INitialize "plateform" and "ans" 
        int platform = 1, ans = 1;
        
        // Using 2-pointer approach initialize i and j
        int i = 1, j = 0;
        
        // Iterate arr and dep through i and j
        while(i < n && j < n) {
            // If arrival time is less form departure time then we need platform
            if(arr[i] <= dep[j]) {
                platform++;
                i++;
            
            // If arrival time is greate from depature time then decrease platform 
            }else if(arr[i] > dep[j]){
                platform--;
                j++;
            }
            
            // We need maximum platforms required
            ans = max(ans, platform);
        }
        
        return ans;
    }
};

// Driver code
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
