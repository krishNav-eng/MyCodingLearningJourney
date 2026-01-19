/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
**/


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // traversal starting from head
        ListNode* t1 = l1; 
        ListNode* t2 = l2;
        int curSum=0;
        int carryover=0;
        
        curSum=t1->val+t2->val+carryover;
        ListNode* rs_hd = new ListNode(curSum%10);
        carryover=curSum/10;

        t1=t1->next;
        t2=t2->next;
        ListNode* prev;
        prev=rs_hd;

        while(true) {
            if(t1==nullptr or t2==nullptr) break;
            curSum=t1->val+t2->val+carryover;
            carryover=curSum/10;
            ListNode* rs_nd = new ListNode(curSum%10);
            prev->next=rs_nd;
            prev=rs_nd;
            t1=t1->next;
            t2=t2->next;
        }
        if(t1!=nullptr) {
            if(carryover<=0) prev->next=t1;
            else {
                while(t1!=nullptr){
                    curSum=t1->val+carryover;
                    ListNode* rs_nd=new ListNode(curSum%10);
                    carryover=curSum/10;
                    prev->next=rs_nd;
                    prev=prev->next;
                    t1=t1->next;
                }
            }
        } else if(t2!=nullptr) {
            if(carryover<=0) prev->next=t2;
            else {
                while(t2!=nullptr){
                    curSum=t2->val+carryover;
                    ListNode* rs_nd=new ListNode(curSum%10);
                    carryover=curSum/10;
                    prev->next=rs_nd;
                    prev=prev->next;
                    t2=t2->next;
                }
            }
        }

        if(carryover>0){
            ListNode* rs_nd=new ListNode(carryover);
            prev->next=rs_nd;
        }

        return rs_hd;
    }


    int cleanSolution(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* tail=&result;
        int carry=0;

        while(l1||l2||carry){
            int sum=carry;
            if(l1) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }

        return result.next;

    }
};