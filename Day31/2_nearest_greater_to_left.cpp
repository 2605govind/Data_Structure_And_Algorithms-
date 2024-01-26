// next_largest_element_aka_nearest_greater_to_left
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Brute forse Time Complexity O(N^2) & Space Complexity O(1)
class Solution_1 {
public:
    std::vector<int> nearestGreaterToLeft(std::vector<int> &arr) {
        int n = arr.size();
        std::vector<int> ans; // Storing nearest greater element

        // Iterate element one by one 
        for(int i = n-1; i >=0; i--) {
            int val = arr[i];

            // Find nearest greater value
            for(int j = i-1; j >=0; j--) {
                if(val < arr[j]) {
                    val = arr[j];
                    break;
                }
            }

            // If val does't have change then print -1
            if(val == arr[i]) {
                ans.push_back(-1);

            // Else val has nearest greater value of arr[i]  
            }else {
                ans.push_back(val);
            }
        }
        
        // "ans" is in reverse oder of correct nearest greater value so reverse it
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// Time Complexity O(N) & Space Complexity O(N)
class Solution_2 {
public:
    std::vector<int> nearestGreaterToLeft(std::vector<int> &arr) {
        int n = arr.size();
        std::vector<int> ans; // Storing nearest greater element
        std::stack<int> s; // Create an empty stack

        // Iterate element one by one 
        for(int i = 0; i < n; i++) {
            
            // If stack empty, It mean arr[i] does't have greater value
            if(s.empty()) {
                ans.push_back(-1);

            // If stack top is greater then arr[i]
            }else if(!s.empty() && s.top() > arr[i]) {
                ans.push_back(s.top());

            }else {
                // If stack top value is not greater arr[i] then pop
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }

                // After "while" operation stack has to condition 
                if(s.empty()) {
                    ans.push_back(-1);
                }else{
                    ans.push_back(s.top());
                }
            }

            s.push(arr[i]);
        }
        
        return ans;
    }    
};

int main() {

    std::cout<<"Enter the number of test case ";
    int testCase;
    std::cin>>testCase;

    // Time complexity O(N^2)
    // Solution_1 s1; 

    // Time complexity O(N)
    Solution_2 s2;

    while(testCase--) {
        int n;

        std::cout<<"\nEnter the size of array ";
        std::cin>>n;

        std::vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            std::cout<<"Enter the "<<i+1<<"th value ";
            std::cin>>nums[i];
        }

        // std::vector<int> ans = s1.nearestGreaterToLeft(nums); // TC O(N^2)
        std::vector<int> ans = s2.nearestGreaterToLeft(nums); // TC O(N)

        for(int i = 0; i < n; i++) {
            std::cout<<ans[i]<<" ";
        }
        std::cout<<"\n\n";
    }
    return 0;
}
