#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev=head;
        ListNode* next;
        ListNode* cur=head->next;
        while(cur){
            if (cur->val==val) {
                cur=cur->next;
                delete e;
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};