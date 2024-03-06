#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* makeList(string str, int pos) {
    string s;
    stringstream ss(str);

    // Node
    ListNode *dummy = new ListNode(0); 
    ListNode *curr = dummy;

    ListNode* circle = nullptr;

    int count = 0;
    while(getline(ss, s, ' ')) {
        count++;
        curr->next = new ListNode(stoi(s));
        curr = curr->next;

        if(count == pos) {
            circle = curr;
        }
    }

    curr->next = circle;
    
    ListNode *temp = dummy;
    dummy = dummy->next;

    delete temp;
    return dummy;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Ege case 
        if(!head || !head->next) return 0;

        ListNode* first = head;
        ListNode* second = head->next;

        while(second && second->next) {
            if(first == second) return 1;

            first = first->next;
            second = second->next->next;
        }
        
        return 0;
    }   
};

int main(){
    string s;
    getline(cin,s);
    int pos; cin>>pos;

    ListNode* head = makeList(s, pos);

    Solution ob;
    cout<<ob.hasCycle(head);
}
