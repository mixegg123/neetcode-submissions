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
    void reorderList(ListNode* head) {
        //find the midnode
        ListNode *slow, *fast, *second;
        slow = head;
        fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        second = slow->next;
        //printf("mid::second->val: %d\n", second->val);
        slow->next = nullptr;
        ListNode *prev = nullptr;
        //reverse the 2nd list
        while(second)
        {
            ListNode *tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }
        second = prev;
        //printf("\t revert::second->val: %d\n", second->val);
        //reorder and produce final list
        while(second)
        {
            ListNode *tmp1 = head->next;
            ListNode *tmp2 = second->next;
            //printf("\t head:%d, second:%d\n", head->val, second->val);
            head->next = second;
            second->next = tmp1;
            head = tmp1;
            second = tmp2;
        }
    }
};
