#include<iostream>
using namespace std;

int main(){
        int maxi = arr[l];
        for(int i=l; i<=r; i++){
            if(maxi <= arr[i]){
                maxi = arr[i];
            }
        }
        
        int size = maxi+1;
        int i = l, j=m+1;
        int pos = l;
        
        while(i <= m && j <= r){
            if(arr[i]%size <= arr[j]%size){
                arr[pos] = arr[i] * size + arr[pos];
                i++;
                pos++;
            }else{
                arr[pos] = arr[j] * size + arr[pos];
                j++;
                pos++;
            }
        }
        
        while(i <= m){
            arr[pos] = arr[i] * size + arr[pos];
            pos++;
            i++;
        }
        
        while(j <= r){
            arr[pos] = arr[j] * size + arr[pos];
            pos++;
            j++;
        }
        
        
        for(int k=l; k<=r; k++){
            arr[k] = arr[k]/size;
        }
}
