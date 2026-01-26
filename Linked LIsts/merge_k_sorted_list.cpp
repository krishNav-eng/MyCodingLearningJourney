#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (true) {
            int idx = -1;
            int min_val = INT_MAX;

            for (int i = 0; i < (int)lists.size(); i++) {
                if (lists[i] && lists[i]->val < min_val) {
                    min_val = lists[i]->val;
                    idx = i;
                }
            }

            if (idx == -1) break;

            tail->next = lists[idx];
            lists[idx] = lists[idx]->next;
            tail = tail->next;
        }

        return dummy.next;
    }
};
