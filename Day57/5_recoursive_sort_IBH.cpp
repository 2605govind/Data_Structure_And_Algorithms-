#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &v, int temp) {
    // Base cose
    if(v.size() == 0 || v[v.size()-1] <= temp){
        v.push_back(temp);
        return;
    }

    // Induction
    int val = v[v.size()-1];
    v.pop_back();

    // Hypothesis
    insert(v, temp);

    v.push_back(val);
}

void recursiveSort(vector<int> &v) {
    // Base case
    if(v.size() == 1) {
        return;
    }

    // Induction
    int temp = v[v.size()-1];
    v.pop_back();

    // Hypothesis
    recursiveSort(v);

    // Function call
    insert(v, temp);
}

int main(){
    vector<int> nums = {2,1,-1,5,7,-4,3};

    // Sort function call
    recursiveSort(nums);

    // Print
    for(auto x : nums) {
        cout<<x<<" ";
    }
}
