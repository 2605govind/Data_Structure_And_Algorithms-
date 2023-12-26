#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void solution(vector<int> &people, vector<int> &ans, int  mask, int i, vector<int> track, int &skill) {
    if(i == people.size()) {
        if(mask == ((1 << skill) - 1)) {
            if(ans.size() == 0 || ans.size() > track.size()) {
                ans.clear();
                for(int j=0; j<track.size(); j++) {
                    ans.push_back(track[j]);
                }
            }
        }
            return;

    }

    solution(people, ans, mask, i + 1,track, skill);

    track.push_back(i);
    solution(people, ans, mask | people[i], i+1,track ,skill);
    track.pop_back();

    // cout<<i<<endl;

    return;
}

int main(){
    int t;
    cin>> t;

    while(t--) {
        unordered_map<string,int> mp;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) {
            string str;
            cin>>str;
            mp[str] = i;
        }

        vector<int> people;

        
        int size;
        cin>>size;
        for(int i=0; i<size; i++) {
            int k;
            cin>>k;
            
            int mask = 0;
            for(int i=0; i<k; i++) {
                string str1;
                cin>>str1;

                mask = mask | 1 << mp[str1];
            }
            people.push_back(mask);

        }

            vector<int> track;
            vector<int> ans;
            solution(people, ans, 0, 0, track, n);

            for(int j =0; j<ans.size(); j++) {
                cout<<ans[j];
            }

    }

    /*
    1
    5
    java cpp c like maths
    4
    2
    java c
    2
    cpp like
    4
    java cpp c like
    1
    maths

    23 output
    */ 
}
