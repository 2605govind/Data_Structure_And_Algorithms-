#include <bits/stdc++.h>
using namespace std;

// TC O(N*logN) & SC O(1)
class Solution_1
{
     bool binarySearch(int arr[], int n, int target) {
        int low = 0, high = n-1, mid;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            
            if(target == arr[mid]) {
                return true;
            }else if(target < arr[mid]) {
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        
        return false;
    }
    
    public:    
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        vector<int> ans;
        
        for(int i = 0; i < n1; i++) {
            if(binarySearch(B, n2, A[i]) && binarySearch(C, n3, A[i])){
                if(ans.size() == 0) ans.push_back(A[i]);;
                
                if(ans.size() >= 1 && ans[ans.size()-1] != A[i]) {
                    ans.push_back(A[i]);
                }
            }
        }
        
        return ans;
    }

};

// TC O(n1 + n2 + n3)  &  SC O(min(n1, n2, n3))
class Solution_2
{
    pair<int*,int> intersection(int A[], int B[], int n1, int n2) {
        int i = 0, j = 0;
        int *array = new int[min(n1,n2)];
        int index = 0;
        while(i < n1 && j < n2) {
            if(A[i] == B[j]) {
                array[index++] = A[i]; 
                // cout<<A[i]<<" ";
                i++, j++;
            }else if(A[i] < B[j]) {
                i++;
            }else {
                j++;
            }
        }

        return {array, index};
    }

    public:    
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        vector<int> vec;
        
        pair<int*,int> arr = intersection(A, B, n1, n2);
        pair<int*,int> ans = intersection(arr.first, C, arr.second, n3);
        delete arr.first;

        for(int i = 0; i < ans.second; i++) {
            vec.push_back(ans.first[i]);
        }

        delete ans.first;
        return vec;
    }

};


// TC O(n1 + n2 + n3)  &  SC O(1)
class Solution_3
{
    public:    
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        vector<int> vec;
        
        int i = 0, j = 0, z = 0;
        while(i < n1 && j < n2 && z < n3) {
            if(A[i] == B[j] && B[j] == C[z]) {
                if(vec.size() == 0) vec.push_back(A[i]);
                
                if(vec.size() >= 1 && vec[vec.size()-1] != A[i]) {
                    vec.push_back(A[i]);
                }
                i++, j++, z++;

            }else if(A[i] < B[j]) {
                i++;

            }else if(B[j] < C[z]) {
                j++;

            }else {
                z++;
            }
        }

        return vec;
    }

};


int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        // Solution_1 ob;
        // Solution_2 ob;
        Solution_3 ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
