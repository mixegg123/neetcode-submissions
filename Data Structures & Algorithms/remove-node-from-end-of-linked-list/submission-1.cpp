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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = head, *second = &dummy;
        second->next = head;
        while(n--)
            fast = fast->next;

        while(fast)
        {
            fast = fast->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
};
