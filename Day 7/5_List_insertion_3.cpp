#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    
    vector<int> vec;
    for(int i = 0; i<n; i++) {
        int val;
        cin>>val;
        vec.push_back(val);
    }
    
    int p;
    cin>>p;
    if(p > n) {
        cout<<"Invalid Input";
        return 0;
    }
    
    int newValue;
    cin>>newValue;
    
    
    vec.insert(vec.begin()+p-1, newValue);
    
    cout<<"Array after insertion is"<<endl;
    for(auto x: vec) {
        cout<<x<<endl;
    }
    
    
    return 0;
}