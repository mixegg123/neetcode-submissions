/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode *cur = &dummy;
        while(l1 && l2)
        {
            int val1 = l1->val;
            int val2 = l2->val;
            int result = val1+val2+carry;
            carry = result>=10 ? 1 : 0;

            cur->next = new ListNode(result%10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *tmp = (l1) ? l1 : l2;
        while(tmp)
        {
            int val = tmp->val + carry;
            carry = (val>=10) ? 1 : 0;
            cur->next = new ListNode(val%10);
            cur = cur->next;
            tmp = tmp->next;
        }

        if(carry)
            cur->next = new ListNode(1);

        return dummy.next;
    }
};
