// program for spriral travelsal on a matrix
#include<iostream>
using namespace std;

void spriralTraversal(int *matrix, int r, int c){

    /*
    
        top-----------------------(i)
              |  1       2       3   |
        left |                         |  right(j)
              |  4       5       6   |
              |                         |
              |  7       8       9   |
        bottom-------------------
    */


    int top = 0;
    int bottom = r-1;
    int left = 0;
    int right = c-1;

    while(top <= bottom && left <= right){
        for (int i = left; i <= right; i++)
        {
            cout<<*(matrix+top*c+i);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout<<*(matrix+i*c+right); // this is a way to point address of elements
        }
        right--;

        if(left <= right){
            for (int i = right; i >= left; i--)
            {
                cout<<*(matrix+bottom*c+i);
            }
            bottom--;
        }
        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout<<*(matrix+i*c+left);
            }
            left++;
        }
    }
}

void inputMatrix(int *matrix, int n, int m){
    cout<<"Enter a matrix \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cin>>*(matrix+i*m+j);
        }
    }
}

void outputMatrix(int *matrix, int n, int m){
    cout<<"Displaying matrix \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cout<<*(matrix+i*m+j)<<" ";
        }cout<<endl;
    }
}

int main(){
    int n = 3;
    int m = 3;
    int fmatrix[n][m];

    inputMatrix((int*)fmatrix,n,m);
    outputMatrix((int*)fmatrix,n,m);

    spriralTraversal((int*)fmatrix,n,m); // this declaration of sending aragument as a ponter 
    return 0;
}