#include<iostream>
#include<vector>
using namespace std;

class OrderedStream {
public:
    int size = 0;
    int ptr = 1;
    string *streamHash;

    OrderedStream(int n) {
        size = n;
        streamHash = new string[n+1];

        for(int i = 0; i<=size; i++){
            streamHash[i] = "";
        }
    }

    ~OrderedStream() {
        delete[] streamHash;
    }

    vector<string> insert(int idKey, string value) {
        if(idKey == ptr) {
            vector<string> ans;
            streamHash[idKey] = value;
            ans.push_back(value);
            ptr++;
            while(ptr <= size && streamHash[ptr] != "") {
                ans.push_back(streamHash[ptr]);
                ptr++;
            }
            
            return ans;
            
        }else {
            streamHash[idKey] = value;
            return {};
        }
    }
};

int main(){
    
}
