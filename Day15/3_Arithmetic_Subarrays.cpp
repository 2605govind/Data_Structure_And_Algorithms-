#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithms>

using namespace std;

class Solution_1 {

    bool checkArithmetic(vector<int> num) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int n = num.size();
        unordered_set<int> uset;
        for(auto x : num) {
            mini = min(mini, x);
            maxi = max(maxi, x);
            uset.insert(x);
        }

        if((maxi - mini)%(n-1) != 0) return false;
        int d = (maxi - mini) / (n-1);

        int c = mini + d;
        while(c < maxi) {
            if(uset.find(c) == uset.end()) return false;
            c += d;
        }

        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i<l.size(); i++) {
            vector<int> temp(nums.begin()+l[i] , nums.begin()+r[i]+1);
            ans.push_back(checkArithmetic(temp) );
        }

        return ans;
    }
};



class Solution_2 {

    bool checkArithmetic(vector<int> num) {
        for(int i = 1; i<num.size(); i++) {
            int diff = num[1]-num[0];
            if(diff != num[i]-num[i-1]){
                return false;
            }
        }
        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i<l.size(); i++) {
            int left = l[i];
            int right = r[i];

            vector<int> temp;
            while(left <= right){
                temp.push_back(nums[left]);
                left++;
            }

            sort(temp.begin(),temp.end());

            if(checkArithmetic(temp)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};

int main(){
    
    
}
