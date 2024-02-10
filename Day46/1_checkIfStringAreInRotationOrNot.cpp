#include<iostream>
using namespace std;

int main(){
//     onbttlakeipmfvblbmoauhg
// bttlakeipmfvblbmoauhgonj
    string s1= "";
    string s2= "forgeeksgeeks";
    int size1=s1.size(), size2=s2.size();
    cout<<size1<<" " <<size2;
    int lps[2*size1+2] = {0};
    char str[2*size1+2];

    for(int i=0; i<size1; i++){
        str[i+1] = s1[i];
        str[size1+2+i] = s2[i];
    }
    str[size1+1] = '&';

    

    // kmp algo
    int first=0;
    int second = 2;

    while(second <2*size1+2 ){
        if(str[first+1] == str[second]){
            lps[second] = first+1;
            first++,second++;
        }else{
            if(first==0){
                second++;
            }else{
                first = lps[first];
            }
        }
    }
    for(int i=1; i<2*size1+2; i++){
        cout<<str[i]<<" ";
    }
    cout<<"\n";
    for(int i=1; i<2*size1+2; i++){
        cout<<lps[i]<<" ";
    }
    int temp = lps[2*size1+1];
    // cout<<size1-temp;
    string finalstr;
    for(int i = size1-temp; i<size1; i++){
        finalstr.push_back(s2[i]);
    }
    for(int i = 0; i<size1-temp; i++){
        finalstr.push_back(s2[i]);
    }

    if(s1 == finalstr){
        cout<<"1";
    }else{
        cout<<"0";
    }

}
