//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int ans;
    vector<int> arr;
    void merge(int l1, int r1, int l2, int r2){
        vector<int> tmp(r2-l1+1);
        int a = l1, b = l2, pos = 0;
        while(a <= r1 and b <= r2){
             if(arr[a] <= arr[b]) tmp[pos++] = arr[a++];
             else ans += (r1 - a + 1), tmp[pos++] = arr[b++];
        }
        while(a <= r1) tmp[pos++] = arr[a++];
        while(b <= r2) tmp[pos++] = arr[b++];
        for(int i = l1; i <= r2; i++) arr[i] = tmp[i-l1];
        return;
    }
    void merge_sort(int l, int r){
        if(l >= r) return;
        int mid = (r + l) / 2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, mid+1, r);
        return;
    }
    int nlogn(int v[] , int n){
        ans = 0, arr.resize(n);
        for(int i = 0; i < n; i++) arr[i] = i * v[i];
        merge_sort(0, n-1);           
        return ans;
    } 
    int countPairs(int arr[] , int n ) {
        return nlogn(arr, n); 
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends