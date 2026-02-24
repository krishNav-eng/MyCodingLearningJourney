#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head||!head->next) return head;
    ListNode dummy(0);
    dummy.next=head;
    ListNode *prev=&dummy;
    for(int i=0;i<left-1;i++) {
        prev=prev->next;
    }
    ListNode *curr=prev->next;
    ListNode *nxt=nullptr;
    for(int i=0;i<right-left;i++) {
        nxt=curr-next;
        curr->next=nxt->next;
        nxt->next=prev->next;
        prev->next=nxt;
    }
    return dummy.next;
}