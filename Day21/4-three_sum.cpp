#include<bits/stdc++.h>
using namespace std;

// this is not remove duplicats
void threeSum(vector<int> vec, int target){
     sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if(i>0 && vec[i] == vec[i-1])
            continue;
        int c = target - vec[i];
        int s = i+1, e = vec.size()-1;
        while (s<e)
        {
       

            if(vec[s]+vec[e] > c)
                e--;
            else if(vec[s]+vec[e] < c )    
                s++;
            else{
                cout<<vec[i]<<" "<<vec[s]<<" "<<vec[e]<<endl;
                if(vec[s] == vec[s+1]) s++;
                if(vec[e] == vec[e-1]) e--;
                s++;
                e--;
            }
                    
        }
        
    }
    
}

int main(){
    vector<int> vec{-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};

    threeSum(vec, 0);
}
