// search element in matrix 
#include<bits/stdc++.h>
using namespace std;

// O(N) && O(1)
class Solution_1 {
public:    

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        // declare index
        int row_index = 0, col_index = col_size-1;

        // if matirx size is 1 then don't execute below code,, just check one element 
        if (row_size == col_size == 1 && matrix[row_size-1][col_size-1] == target)
            return true;

        // traverse diagonal elements (right to left) untill we get target
        while (row_index < row_size && col_index > -1) {
            // if we get target
            if (target == matrix[row_index][col_index]) {
                return true;
            }

            // if target is small from current value then move (left side) less values
            if (target < matrix[row_index][col_index]) {
                col_index--;
            }

            // if we get target
            if (target == matrix[row_index][col_index]) {
                return true;
            }

            // if target is large from current value then move down side
            if (target > matrix[row_index][col_index]) {
                row_index++;
            }
        }
        // if target is not found
        return 0;
    }    
};


// second approach O(logn*logm)
class Solution_2 {
public:

    bool searchElementInMatrix(vector<vector<int>>& matrix, int target) {
        // initialize size
        int n = matrix.size();
        int m = matrix[0].size();

        // using binary search, declare variables
        int rowstart = 0, rowend = n-1, rowmid;
        int col_sizerstart = 0, col_end = m-1, col_mid;

        // searching in row_size by binary search
        while(rowstart <= rowend) {
            rowmid = (rowstart + rowend) / 2;

            // if row_size get target at mid index
            if (matrix[rowmid][0] == target) {
                return true;
            }

            // searching in col_sizeom by binary search
            col_sizerstart = 0, col_end = m-1;
            while(col_sizerstart <= col_end) {
                col_mid = (col_sizerstart + col_end) / 2;

                if (matrix[col_mid][col_mid] == target) {
                    return true;
                } else if (matrix[col_mid][col_mid] < target) {
                    col_sizerstart= col_mid + 1;
                } else {
                    col_end= col_mid -1 ;
                }
            }

            // update rowstart & col_sizestart based on mid index
            if( matrix[rowmid][0] < target ){
                rowstart = rowmid + 1;
            } else {
                rowend = rowmid - 1;
            }
        }

        // if row_size not get target then return false
        return false;
    }

};

int main(){
    // creating, insertng values in martix
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8},{9,10,11,12}};
    int target = 78;

    Solution_1  s1;
    int found = s1.searchMatrix(matrix, target);

    // print result
    if (found) {
        cout<< "Target found " << endl;
    } else {
        cout<< "Not! Target found " <<endl;
    }

}
