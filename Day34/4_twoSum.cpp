#include<bits/stdc++.h>
using namespace std;

int main(){
    multimap<int,int> m;
    int array[] = {3,5,3};
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        m.insert(pair<int, int>(i,array[i]));
    }
     for (auto x : m)
    cout << x.first << " " << 
            x.second << endl;
    
}