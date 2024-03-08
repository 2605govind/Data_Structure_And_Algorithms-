#include <bits/stdc++.h>
using namespace std;

// Time complexity O(N) & Space complexity O(26) ~ code by Govind Suthar
class Solution{
public:	
	bool sameFreq(string s) {   
	    // Storing frequence of charactor
	    unordered_map<char,int> mp;
	    for(auto x : s) {
	        mp[x]++;
	    }
	    
	    // Count refere 1 charactor which we have to remove
	    int count = 1;
	    int val = 0;
	    // Iterate all occurence one by one
	    for(auto x : mp) {
	        // First time loop run then store first value in val for compair
	        if(val == 0) {
	            val = x.second;
	        
	        // Now compair and find a valid match      
	        }else {
    	        if(val == x.second) {
    	            continue;
    	        
    	        // If difference is one mean we can remove one charactor after then count become zero 
    	        }else if(count && val != x.second && abs(val-x.second) == 1) {
    	            count--;
    	            val = min(val, x.second);
    	        
    	        // If given string is not equal all frequencis then return false     
    	        }else {
    	            return false;
    	        }
	        }
	    }
	    
	    // Agter loop completion we can say that frequencies can be equal
	    return true;
	}
};

int main(){
    int t;
    cout<<"Enter number of test case: ";
    cin>>t;
    while(t--)
    {
        cout<<"Enter your string : ";
        string s;
        cin>>s;
        Solution ob;
        if(ob.sameFreq(s)){
            cout<<"\nFrequencies is equal\n\n";
        }else {
            cout<<"\nFrequencies is not equal\n\n";
        }
    }
}
