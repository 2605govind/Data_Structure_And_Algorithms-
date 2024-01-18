#include<bits/stdc++.h>
using namespace std;

// Function : move all element to end
void segregateElements(int arr[],int n){
    stack<int> s;
    // pushing all positive in stack
    for(int i=0; i<n; i++){
        if(arr[i] < 0)
            s.push(arr[i]);
    }
    
    // if array contains all elements are +ve and -ve;
    if(s.size() ==0 || s.size() == n){
        return;
    }

    int ind=0;
    // inserting all postive in left side
    for(int i=0; i<n; i++){
        if(arr[i] >= 0)
            arr[ind++] = arr[i];
    }
    
    // inserting all nagative ele right side
    ind=n-1;
    while(s.size()){
        arr[ind--] = s.top();
        s.pop();
    }
}

// Print array element
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int array[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = sizeof(array)/sizeof(array[0]);

    // Befor segregate array
    print(array, n);

    segregateElements(array, n);

    // After segregate array
    print(array, n);

    return 0;
}
