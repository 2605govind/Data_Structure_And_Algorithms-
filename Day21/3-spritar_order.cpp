#include<bits/stdc++.h>
using namespace std;

void spritalOder(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int top=0;
    int down=n-1;

    int left = 0;
    int right = m-1;

    while(left <= right || top <= down){
        // upper part
        for(int i = left; i <= right; i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;

        //Right part
        for(int i = top; i <= down; i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;

        // lower part
        for(int i = right; i > left; i--){
            cout<<matrix[down][i]<<" ";
        }
        down--;
        // [1,2,3,4,8,12,11,10,9,5,6,7]
        // left part
        for(int i = down; i > top; i--){
            cout<<matrix[i][left]<<" ";
        }
        left++;
    }

    // 
}

int main(){
    vector<vector<int>> vec{{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    spritalOder(vec);
}
