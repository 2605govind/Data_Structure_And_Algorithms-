// next_smallest_element_aka_nearest_smallest_to_right
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Brute forse Time Complexity O(N^2) & Space Complexity O(1)
class Solution_1 {
public:
    std::vector<int> nearestSmallestToRight(std::vector<int> &arr) {
        int n = arr.size();
        std::vector<int> ans; // Storing nearest smallest element

        // Iterate element one by one 
        for(int i = n-1; i >= 0; i--) {
            int val = arr[i];

            // Find nearest smallest value
            for(int j = i+1; j < n; j++) {
                if(val > arr[j]) {
                    val = arr[j];
                    break;
                }
            }

            // If val does't have change then print -1
            if(val == arr[i]) {
                ans.push_back(-1);

            // Else val has nearest smallest value of arr[i]  
            }else {
                ans.push_back(val);
            }
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// Time Complexity O(N) & Space Complexity O(N)
class Solution_2 {
public:
    std::vector<int> nearestSmallestToRight(std::vector<int> &arr) {
        int n = arr.size();
        std::vector<int> ans; // Storing nearest smallest element
        std::stack<int> s; // Create an empty stack

        // Iterate element one by one 
        for(int i = n; i >= 0; i--) {
            
            // If stack empty, It mean arr[i] does't have greater value
            if(s.empty()) {
                ans.push_back(-1);

            // If stack top is smallest then arr[i]
            }else if(!s.empty() && s.top() < arr[i]) {
                ans.push_back(s.top());

            }else {
                // If stack top value is not smallest arr[i] then pop
                while(!s.empty() && s.top() >= arr[i]){
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
 
        reverse(ans.begin(), ans.end());

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

        // std::vector<int> ans = s1.nearestSmallestToRight(nums); // TC O(N^2)
        std::vector<int> ans = s2.nearestSmallestToRight(nums); // TC O(N)

        for(int i = 0; i < n; i++) {
            std::cout<<ans[i]<<" ";
        }
        std::cout<<"\n\n";
    }
    
    return 0;
}


/*  
    OutPut:-
    
    Enter the number of test case 2

    Enter the size of array 6
    Enter the 1th value 1        
    Enter the 2th value 9
    Enter the 3th value 2
    Enter the 4th value 4
    Enter the 5th value 3
    Enter the 6th value 5
    -1 2 -1 3 -1 -1         


    Enter the size of array 4
    Enter the 1th value 1
    Enter the 2th value 7
    Enter the 3th value 3
    Enter the 4th value 5
    -1 3 -1 -1 
    
*/
