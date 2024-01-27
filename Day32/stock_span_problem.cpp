// Stock span problem :- consecutive smallest to left
#include <iostream>
#include <vector> 
#include <stack>

// Brute forse solution | Time Complexit O(N^2) & Space Complexity O(1)
class Solution_1 {  
public:    
    // Method for finding consecutive smallest to left side
    std::vector<int> consecutiveSmallest(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n); // Storing count of consecutive smallest of a target value

        for(int i = 0; i < n; i++) {
            int res = 1; // Initially count of consecutive smallest of value is 1 

            for(int j = i-1; j >= 0; j--) {
                // If element is small then target element "nums[i]" then increase res by 1
                if(nums[i] >= nums[j]){
                    res++;
                // Else break it because we need consecutive     
                }else {
                    break;
                }
            }

            // Insert res in "ans"
            ans[i] = res;
        }

        return ans;
    }
};

// Optimize solution using stack | Time Complexit O(N) & Space Complexity O(N)
class Solution_2 {
public:
    std::vector<int> countConsecutiveSmallestUsingStack(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n); // Storing consecutive smallest element.
        std::stack<std::pair<int,int>> st; // Create empty stack for storing elment and consecutive count.

        // Iterate one by one all elements
        for(int i = 0; i < n; i++) {
            int res = 1; // Initially consecutive smallest count 1 because given condition is smallest and equle consecutive

            // If nums[i] greater then and equel to stack top then 
            while(!st.empty() && st.top().first <= nums[i]) {
                // Every stack top second containt consecutive count 
                res += st.top().second;
                st.pop();
            }

            ans[i] = res;

            // Now, push in stack
            st.push({nums[i], res});
        }

        return ans;
    }
};

// Optimize solution using stack(nearest greater to left) | Time Complexit O(N) & Space Complexity O(N)
class Solution_3 {
public:
    std::vector<int> countConsecutiveSmallestUsingStack(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n); // Storing consecutive smallest element.
        std::stack<std::pair<int,int>> st; // Create empty stack for storing elment and index

        // Iterate one by one all elements
        for(int i = 0; i < n; i++) {

            // If nums[i] greater then and equel to stack top then 
            while(!st.empty() && st.top().first <= nums[i]) {
                st.pop();
            }

            // If stack is empty it's mean no greater element and st.top().second is nearest greater element index
            ans[i] = (st.empty()) ? -1 : st.top().second;

            // Push in stack element and it index
            st.push({nums[i], i});
        }

        int size = ans.size();
        // Iterate "ans" and currect index and nearest greater element index diffrence is count of consecutive element 
        for(int i = 0; i < size; i++) {
            ans[i] = i - ans[i];
        }

        return ans;
    }
};

int main() {
    int testCase;
    std::cout<<"\nEnter number of test case = ";
    std::cin>>testCase;

    // Solution_1 s1;
    // Solution_2 s2;
    Solution_3 s3;


    while(testCase--) {
        int n;
        std::cout<<"\n\nEnter the size of array = ";
        std::cin>>n;
        std::vector<int> nums(n);

        // Take input 
        for(int i = 0; i < n; i++) {
            std::cout<<"Enter the "<<i+1<<"_th value = ";
            std::cin>>nums[i];
        }

        // std::vector<int> ans = s1.consecutiveSmallest(nums); // TC O(N^2)
        // std::vector<int> ans = s2.countConsecutiveSmallestUsingStack(nums); // TC O(N)
        std::vector<int> ans = s3.countConsecutiveSmallestUsingStack(nums); // TC O(N)

        // Print output
        for(int i = 0; i < n; i++) {
            std::cout<<ans[i]<<" ";
        }
        
    }

    return 0;
}

/*
    OutPut:

    Enter number of test case = 2

    Enter the size of array = 7
    Enter the 1_th value = 100
    Enter the 2_th value = 80
    Enter the 3_th value = 60
    Enter the 4_th value = 70
    Enter the 5_th value = 60
    Enter the 6_th value = 75
    Enter the 7_th value = 85
    1 1 1 2 1 4 6 

    Enter the size of array = 4
    Enter the 1_th value = 5
    Enter the 2_th value = 23
    Enter the 3_th value = 67
    Enter the 4_th value = 34
    1 2 3 1 
*/