#include<iostream>
#include<vector>
using namespace std;

void incresElement(vector<int> &num, int n, int m) {
    for(int i = 0; i< num.size(); i++) {
        int diff = abs(num[i] - n ); 
        if(diff < m) {
            num[i]++;
        }
    }
}

void printArray(vector<int> &num){
    for(int i = 0; i< num.size(); i++) {
        cout<<num[i]<<" ";
    }
    cout<<" \n";
}

int main(){
    int size, n, m;
    cin>>size>>n>>m;
    vector<int> num(size);

    for(int i = 0; i< size; i++) {
        cin>>num[i];
    }

    printArray(num);

    incresElement(num, n, m);
    printArray(num);

    /*
        7
        4 3
        7 3 1 4 5 6 8
    */
    return 0;
}
