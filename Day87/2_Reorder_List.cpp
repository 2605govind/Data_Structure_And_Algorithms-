#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(vector<int> &vec, int n) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    if(head == nullptr) {
        head = new ListNode(vec[0]);
    }
    
    curr = head;
    for(int i = 1; i < n; i++) {
        curr->next = new ListNode(vec[i]);
        curr = curr->next;
    }
    

    return head;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        // find mid
        ListNode* mid = head;
        ListNode* curr = head->next;
        while(curr && curr->next) {
            mid = mid->next;
            curr = curr->next->next;
        }

        // Reverse right mid part
        ListNode* prev = nullptr;
        curr = mid->next;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        mid->next = nullptr;
        ListNode* dummy_node = new ListNode(0);
        ListNode* dummy = dummy_node;

        curr = prev;
        while(head && curr) {
            dummy->next = head;
            dummy = head;
            head = head->next;

            dummy->next = curr;
            dummy = curr;
            curr = curr->next;
        }

        if(head) {
            dummy->next = head;
        }

        if(curr) {
            dummy->next = curr;
        }

        head = dummy_node->next;
    }
};

void print(ListNode* head) {
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--) {
        int n;
        cout<<"Enter size of list "; cin>>n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++) 
            cin>>vec[i];

        ListNode* head = createList(vec, n);    
        print(head);

        Solution s;
        s.reorderList(head);
        print(head);
    }
}
