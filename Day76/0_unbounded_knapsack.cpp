#include<iostream>
#include<vector>
using namespace std;

// Recursive way
class Solution_1{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        if(W == 0 || N == 0) return 0;
        
        if(wt[N-1] <= W) {
            return max(val[N-1] + knapSack(N, W-val[N-1], val, wt), knapSack(N-1, W, val, wt));
            
        }else {
            return knapSack(N-1, W, val, wt);
        }
    }
};

// Memoize
class Solution_2{
    int solver(int N, int W, int val[], int wt[], vector<vector<int>> &t) {
        if(W == 0 || N == 0) return 0;
        
        if(t[N][W] != -1) {
            return t[N][W];
        }
        
        if(wt[N-1] <= W) {
            return t[N][W] = max(val[N-1] + solver(N, W-wt[N-1], val, wt, t), solver(N-1, W, val, wt, t));
            
        }else {
            return t[N][W] = solver(N-1, W, val, wt, t);
        }
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> t(N+1, vector<int>(W+1, -1));
        
        return solver(N, W, val, wt, t);
    }
};

// Top-down 
class Solution_3{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> t(N+1, vector<int>(W+1, 0));
        
        for(int i = 1; i < N+1; i++) {
            for(int j = 1; j < W+1; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
                }else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[N][W];
    }
};


int main(){
    int val[]  = {1, 30};
    int wt[] = {1, 50};
    int W = 100;

    // Output : 100

    Solution_1 s;
    cout<<s.knapSack(2, W, val, wt);

}
