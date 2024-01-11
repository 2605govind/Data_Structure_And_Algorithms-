#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int target){
    int low = 0; 
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(a[mid] < target){
            low = mid+1;
        }else if(a[mid] > target){
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int array[] = {1,2,3,4,5,6};
    int n = 6;

    cout<<binarySearch(array, n, 3);
}
