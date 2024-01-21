#include<iostream>
using namespace std;

void combinationSum(int arr[],int size, int index, int total, int target,int &ans){
    if(index >= size){
        if(total == target){
            ans = 1;        
        }
        return;
    }

    if(total > target)
        return;

            
    combinationSum(arr,size,index+1,total,target,ans);
    combinationSum(arr,size,index,total+arr[index],target,ans);
    
} 

void print(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }cout<<"\n";
    
}

int main(){
    int array[] = {1,2,3};
    int n = sizeof(array)/sizeof(array[0]);
    int total=0;
    int target = 11;
    int ans = 0;
    combinationSum(array,n,0,total,target,ans);

    cout<<ans;

}
