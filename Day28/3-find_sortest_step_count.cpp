#include <iostream>
using namespace std;


// findin minimum number of jump
int shortestPathArray(int *array, int size){
    int max = 0;
    int i = 0;
    int count = array[0];
    int step = 1;
    i = i + count;
    int cur_jump_value;
    int b = 1;

    while(i < size){

        cur_jump_value = array[i];

        if(max < array[cur_jump_value+b]){

            // finding maximum jump value
            max = array[cur_jump_value+b];

            // for end of element
            if(i == size-1){
                return ++step;
            }
        }
        if(b <= cur_jump_value){
            b++;
        }

        if(cur_jump_value==b){
            i = max + i;
            step++;
            b = 1;
            // cout<<a<<" ";
        }
        cur_jump_value--;
    }
    return step;
    
}

// print complete array 
void print_Array(int A[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}


int main(){
    int A[] = {1,2,5,8,9,2,6,7,6,8,9};
    int n = sizeof(A)/sizeof(int);
    print_Array(A,n);
    cout<<shortestPathArray(A,n);

    // output  
    // 1 4 3 2 6 7 
    // 2

    // 1 2 5 8 9 2 6 7 6 8 9 
    // 3

    return 0;
}