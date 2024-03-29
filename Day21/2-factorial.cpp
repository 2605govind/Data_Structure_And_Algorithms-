#include<bits/stdc++.h>
using namespace std;


void multiply(vector<int> &arr, int& size, int multiplier){
    int carry = 0;
            
    for(int i = 0; i < size; i++){
        int res = multiplier * arr[i];
        res = res + carry;
        
        arr[i] = res%10;
        carry = res /10;
        cout<<arr[i];
    }
    
    while(carry > 0){
        arr[size] = carry%10;
        size++;
        carry /= 10;
    }
}

vector<int> factorial(int N)
{
        vector<int> arr(10000, 0);
        arr[0] = 1;
        int size = 1;
        
        for(int multiplier = 2; multiplier <= N; multiplier++){
            multiply(arr, size, multiplier);
        }
        
        vector<int> result;

        for(int i = size-1; i >= 0; i--){
            result.push_back(arr[i]); 
        }
        return result;
    }

int main(){
    factorial(5);
}
