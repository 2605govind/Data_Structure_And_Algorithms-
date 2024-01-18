#include<iostream>
using namespace std;

int missingNumber(int A[], int N){ 
    int sum = N*(N+1)/2;
    for(int i=0; i<N-1; i++){
        sum = sum-A[i];
    }
    
    return sum;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        int val;
        for(int i=0; i<n; i++){
            cin>>val;
            arr[i] = val;
        }

        cout<<"missing number is "<<missingNumber(arr,n);
    }
    
}

