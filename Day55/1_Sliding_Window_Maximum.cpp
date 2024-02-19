#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<int>slidingMaximum(const vector<int> &A, int k) {
    // Storing max element of window
    list<int> l;
    
    // Storing output
    vector<int> ans;
    
    int n = A.size();
    
    // Initialize sliding window technique
    int i = 0, j = 0;
    while(j < n) {
        // list back is smallest then arr[j] then pop because no need of these element
        while(!l.empty() && l.back() < A[j]) {
            l.pop_back();
        }
        // Now push jth
        l.push_back(A[j]);
        
        // Move j till window is not created
        if((j-i+1) < k) {
            j++;
            
        // Window is created    
        }else{
            // push max of window element 
            ans.push_back(l.front());
            
            // Now remove ith element
            if(l.front() == A[i]) {
                l.pop_front();
            }
            
            // Slide the window
            i++, j++;
        }
    }
    
    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = slidingMaximum(nums, k);

    for(auto x : ans) {
        cout<<x<<" ";
    }
}
