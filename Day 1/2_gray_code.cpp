#include<iostream>
#include<vector>
using namespace std;

vector<string> grayCode(int n) {
    if(n == 1) {
        vector<string> mat;
        mat.push_back("0");
        mat.push_back("1");
        return mat;
    }

    vector<string> vec = grayCode(n-1);
    vector<string> mat;

    int k = vec.size();
    for(int i = 0; i<k; i++) {
        mat.push_back('0' + vec[i]);
    }

    for(int i = k-1; i>=0; i--) {
        mat.push_back('1' + vec[i]);
    }

    return mat;
}


int main(){
    int n  = 3;

    vector<string> mat = grayCode(n);
    for(int i=0; i<mat.size(); i++) {
        cout<<mat[i]<<endl;
    }
}
