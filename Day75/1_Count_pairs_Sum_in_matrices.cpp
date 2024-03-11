#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
        // Using two pointer
        int i = 0, j = (n*n-1), count = 0;
        
        while(i < (n*n) && j >= 0) {
            int a = mat1[i/n][i%n];
            int b = mat2[j/n][j%n];
            
            if(a + b == x) {
                count++;
                i++;
                j--;
            }else if(a + b < x) {
                i++;
            }else{
                j--;
            }
            
        }
        
        return count;
	}
};

int main() {

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}

/*

    https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1
    
    Input: 
    n = 3, x = 21
    mat1 = {{1, 5, 6},
            {8, 10, 11},
            {15, 16, 18}}
    mat2 = {{2, 4, 7},
            {9, 10, 12},
            {13, 16, 20}}
    OUTPUT: 4

*/