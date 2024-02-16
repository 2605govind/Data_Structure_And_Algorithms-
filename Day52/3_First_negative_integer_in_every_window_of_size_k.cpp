#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}


vector<long long> printFirstNegativeInteger(long long int A[], long long int n, long long int k) {
    // Storing negative number
    list<long long int> l;
    // i and j for making window
    long long int j = 0, i = 0; 

    // Storing final output
    vector<long long> ans;
    
    while(j < n) {
        // If jth element negative then push in list
        if(A[j] < 0) {
            l.push_back(A[j]);
        }
        
        // Create window 
        if((j - i + 1) < k){
            j++;

        // Now check first negative element in window using list    
        }else{
            
            // If list size zero then push 0
            if(l.size() == 0){
                ans.push_back(0);

            // If list size non zero then push list front element
            }else{
                ans.push_back(l.front());
            }
            
            // If ith element of window we have to remove so remove at list also 
            if(A[i] == l.front()) {
                l.pop_front();
            }
            
            // Now slide the window
            i++; j++;
        }
    }
    
    return ans;                                                                         
}

/*output
    1
    5
    -8 2 3 -6 10     
    2
    -8 0 -6 -6
*/