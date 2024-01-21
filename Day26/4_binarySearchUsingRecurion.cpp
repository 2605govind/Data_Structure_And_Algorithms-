#include<iostream>
using namespace std;

int binarySearch(int a[],int first, int end, int key){

    if(first > end) return -1;
    int mid = (first+end)/2;

    if(a[mid] == key)
        return mid+1;
    else if(a[mid] > key){
        return binarySearch(a,first,mid-1,key);
    }else{
        return binarySearch(a,mid+1,end,key);
    }    
}

int main(){
    int array[] = {1,20,45,67,68,90};
    int n = sizeof(array)/sizeof(array[0]);
    int key = 68;
    cout<<binarySearch(array,0,n-1,key);
}
