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
    ListNode* reverseKGroup(ListNode* head, int k) {
/*
        prev= nullptr;
        //reverse node
        tmp = node1->next;
        node1->next = prev;
        prev=node1
        node1=tmp;
*/
        ListNode dummy;
        ListNode *prevTail = &dummy;
        ListNode *slow, *fast;
        fast = slow = head;
        while(fast)
        {
            int cnt = 0;
            while(fast && cnt < k)
            {
                fast = fast->next;
                cnt++;
            }

            //break condition
            if(cnt != k)
            {
                prevTail->next = slow;
                break;
            }

            //in-place reverse list
            ListNode *prev = nullptr;
            ListNode *groupTail = slow;
            while(slow != fast)
            {
                ListNode *next = slow->next;
                slow->next = prev;
                prev = slow;
                slow = next;
            }
            prevTail->next = prev;
            prevTail = groupTail;
            cnt = k;

        }
        return dummy.next;
    }
};
