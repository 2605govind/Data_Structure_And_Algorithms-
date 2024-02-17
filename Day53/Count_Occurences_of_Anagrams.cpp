#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC O(26 * N) Where N is size of "txt" & SC O(26)
class Solution_1{
public:
	int search(string pat, string txt) {
	    // Storing occurence
	    vector<int> hsh(26);
	    vector<int> test(26);
	    
	    // Storing pattern string occurence in "test"
	    for(int i = 0; i<pat.size(); i++) {
	        test[pat[i]-'a']++;
	    }
	    
	    // Initialize 
	    int i = 0, j = 0, k = pat.size(), n = txt.size(), count = 0;
	    
	    // Using sliding window approach
	    while(j < n) {
	        // Increment occurence 
	        hsh[txt[j]-'a']++;
	        
	        // Window is creating 
	        if((j-i+1) < k) {
	            j++;
	        
	        // Window created     
	        }else {
	            // Check occurence of hsh and test 
	            int p;
	            for(p = 0; p<26; p++) {
	                // If occurence is not equle the break
	                if(hsh[p] != test[p])
	                break;
	            }
	            
	            // If p == 26 mean we successfuly check
	            if(p == 26) {
	                count++;
	            }
	            
	            // Move window 
	            hsh[txt[i]-'a']--;
	            i++, j++;
	        }
	    }
	    
	    return count;
	}

};

// TC O(N) Where N is size of "txt" & SC O(26)
class Solution_2{
public:
	int search(string pat, string txt) {
	    // Calculate occurence of "pat" string
	    unordered_map<int,int> mp;
	    for(auto s : pat) {
	        mp[s]++;
	    }
	    
	    // Initialize
	    int i = 0, j = 0, k = pat.size(), count = mp.size(), n = txt.size(), ans = 0;
	    
	    // Using sliding window
	    while(j < n) {
	        // If latter is present then decrease occurence
	        if(mp.find(txt[j]) != mp.end()){
	            mp[txt[j]]--;
	        }
	        
	        // If latter occurence is zero then decrease count
	        if(mp.find(txt[j]) != mp.end() && mp[txt[j]] == 0){
	            count--;
	        }
	        
	        // If window is creating 
	        if((j-i+1) < k) {
	            j++;
	            
	        // If window has created 
	        }else{
	           // If count is zero it mean we get an anagram
	           if(count == 0) {
	               ans++;
	           }
	           
	           // Now checking for ith index latter
	           if(mp.find(txt[i]) != mp.end()){
	                mp[txt[i]]++;
	           }
	           
	           // If agina ith latter occurence is 1 then increase count
	           if(mp.find(txt[i]) != mp.end() && mp[txt[i]] == 1){
	               count++;
	           }
	           
	           // Slide window
	           i++, j++;
	        }
	        
	    }
	    
	    return ans;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution_2 ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}

/*
    Input:
    1
    forxxorfxdofr
    for

    Output:
    3
*/