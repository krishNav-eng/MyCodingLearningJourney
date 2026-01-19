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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode* prev = head;

        while (prev) {
            int dup = prev->val;
            ListNode* uni = prev;
            prev = prev->next;

            while (prev != nullptr && dup == prev->val) {
                ListNode* duplicateNode = prev;  // delete current
                prev = prev->next;
                delete duplicateNode;
            }

            uni->next = prev;
        }

        return head;
    }

};