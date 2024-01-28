// Rain water trapping code by Govind
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Brute forse, Time complexity O(N^2) & Space complexity O(1)
class Solution_1 {
public:
    // Method for calculative trap water 
    int rainWaterTrap(std::vector<int> &nums) {
        int n = nums.size();

        int trapWater = 0; // Initialize 0 at begining we have zero unit of water

        // One by one find water on above each building
        for(int i = 0; i < n; i++) {
            int maxLeft = nums[i];
            int maxRight = nums[i];

            // Find maximum building at left side
            for(int j = i-1; j >=0; j--) {
                maxLeft = std::max(maxLeft, nums[j]);
            }

            // Find maximum building at right side
            for(int j = i+1; j < n; j++) {
                maxRight = std::max(maxRight, nums[j]);
            }

            // Calculative water above every building and add in trapWater
            trapWater += std::min(maxLeft, maxRight) - nums[i];
        }

        return trapWater;
    }

};

// Best solution, Time complexity O(N) & Sapce complexity O(N)
class Solution_2 {
    // Method for finding left grater value of current element
    std::vector<int> greaterLeft(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        ans[0] = nums[0];
        for(int i = 1; i < n; i++) {
            ans[i] = std::max(nums[i], ans[i-1]);
        }

        return ans;
    }

    // Method for finding right grater value of current element
    std::vector<int> greaterRight(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        ans[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            ans[i] = std::max(nums[i], ans[i+1]);
        }

        return ans;
    }

public:
    // Finding trap water using extra space
    int trapRainWater(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> maxLeft = greaterLeft(nums);
        std::vector<int> maxRight = greaterRight(nums);
        int trapWater = 0; // Initialize 0 at begining we have zero unit of water

        for(int i = 0; i < n; i++) {
            trapWater += std::min(maxLeft[i], maxRight[i]) - nums[i];
        }

        return trapWater;
    }
};

int main() {
    std::cout<<"Enter number of test case :- ";
    int testCase;
    std::cin>>testCase;

    // Solution_1 s1;
    Solution_2 s2;

    while(testCase-- && testCase > -1) {
        std::cout<<"\nEnter the size of array :- ";
        int n;
        std::cin>>n;

        std::vector<int> nums(n);

        for(int i = 0; i < n; i++) {
            std::cout<<"Enter "<<i+1<<"_th element ";
            std::cin>>nums[i];
        }
        
        // int water = s1.rainWaterTrap(nums);
        int water = s2.trapRainWater(nums);

        std::cout<<"\nTrap water is "<<water<<"\n\n";
    }

    return 0;
}

/*
    Output:-
    Enter number of test case :- 2

    Enter the size of array :- 6
    Enter 1_th element 3
    Enter 2_th element 0
    Enter 3_th element 0
    Enter 4_th element 2
    Enter 5_th element 0
    Enter 6_th element 5

    Trap water is 10


    Enter the size of array :- 12
    Enter 1_th element 0
    Enter 2_th element 1
    Enter 3_th element 0
    Enter 4_th element 2
    Enter 5_th element 1
    Enter 6_th element 0
    Enter 7_th element 1
    Enter 8_th element 3
    Enter 9_th element 2
    Enter 10_th element 1
    Enter 11_th element 2
    Enter 12_th element 2

    Trap water is 6
*/
