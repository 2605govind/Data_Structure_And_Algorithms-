#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> nums(5);
    
    for (int i = 0; i < 5; i++)
    {
        nums[i].resize(i+1,1);
        for (int j = 1; j < i; j++)
        {
            nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
        }                                                                                                
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<nums[i][j]<<" ";
        }
        cout<<"\n";                                                                                                                       
    }
}
