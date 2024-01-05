#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> multiplication(vector<vector<int>> &mat1, vector<vector<int>> &mat2 ) {
    int row = mat1.size();
    int col = mat2[0].size();
    vector<vector<int>> multi(row, vector<int>(col) );

    if(mat1[0].size() != mat2.size()) {
        cout<<"Can't Multiplay!"<<endl;
        return multi; // Handling edge cases when this is not setisfy matrix multiplication
    }

    int commonSize = mat1[0].size();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            for(int k = 0; k < commonSize; k++) {
                multi[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return multi;
}

void printMatrix(vector<vector<int>> &mat) {
    int row = mat.size();
    int col = mat[0].size();

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void maximumRow(vector<vector<int>> mat) {
    int row = mat.size();
    int col = mat[0].size();

    pair<int,int> mx;
    mx.first =  mat[0][0];
    mx.second = 0;  

    for(int i = 0; i<row; i++) {
        int sum = 0;
        for(int j = 0; j<col; j++) {
            sum += mat[i][j];
        }
        if(sum > mx.first) {
            mx.first = sum;
            mx.second = i+1;
        }
    }

    cout<<"Maximum row is "<<mx.second<<endl;
}

int main(){
    // Take input from user 
    
    int row, col;
    cin>>row>>col;
    vector<vector<int>> mat1(row, vector<int>(col) );
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>mat1[i][j];
        }
    }

    cin>>row>>col;
    vector<vector<int>> mat2(row, vector<int>(col) );
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>mat2[i][j];
        }
    }

    
    printMatrix(mat1);
    cout<<endl;
    printMatrix(mat2);
    cout<<endl;

    vector<vector<int>> multi = multiplication(mat1, mat2);
    printMatrix(multi);

    maximumRow(multi);

    /*
        input:
        3 3
        1 2 3
        4 5 6
        7 8 9

        3 2
        1 2
        4 5
        6 7

        output:
        27 33
        60 75
        93 117


        input:
        3 3
        1 2 3
        4 5 6
        7 8 9

        3 3
        9 8 7
        6 5 4
        3 2 1

        ouput:
        30 24 18
        84 69 54
        138 114 90
        Maximum row is 3
    */
}
