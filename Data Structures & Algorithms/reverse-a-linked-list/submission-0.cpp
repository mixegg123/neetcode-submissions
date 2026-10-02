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
    ListNode* reverseList(ListNode* head) {
        //stack and LIFO to construct ListNode
#if 1
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while(cur)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            // update node cur to prev, tmp is new cur
            prev = cur;
            cur = tmp;
        }
        return prev;
#else
        ListNode dummy(0);
        stack<ListNode *> st;
        while(head)
        {
            st.push(head);
            head = head->next;
        }

        ListNode *tmp = &dummy;
        while(!st.empty())
        {
            tmp->next = st.top();
            tmp = tmp->next;
            st.pop();
        }
        return dummy.next;
#endif
    }
};
