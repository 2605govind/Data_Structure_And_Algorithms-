#include<bits/stdc++.h>
using namespace std;

int secondLargest(int a[], int n){
    int maxi = INT_MIN;
    int second = INT_MIN;
    
    for(int i=0; i<n; i++){
        if(maxi < a[i])
            maxi = a[i];
    }

    for(int i=0; i<n; i++){
        if(a[i] < maxi && a[i] > second)
            second = a[i]; 
    }

    return second;
}

int main(){
    int array[] = {1,6,3,7,3,3,4};
    int n = sizeof(array)/sizeof(array[0]);

    cout<<secondLargest(array,n);
}
