#include<iostream>
using namespace std;

const int N = 1e5+10;
int hsh[N][26];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        for (int i = 0; i < n; i++)
        {
            hsh[i+1][s[i]-'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[j][i] += hsh[j-1][i];
            }
            
        }
        
        while (q--){
            int l,r,oddcount=0;
            cin>>l>>r;
            for (int i = 0; i < 26; i++)
            {
                int charcount = hsh[r][i] - hsh[l-1][i]; 
                if (charcount%2!=0)
                {
                    oddcount++;
                }
                
            }

            if (oddcount > 1)
            {
                cout<<"No"<<endl;
            }else{
                cout<<"Yess"<<endl;
            }
            
            
        }
        
    }
}