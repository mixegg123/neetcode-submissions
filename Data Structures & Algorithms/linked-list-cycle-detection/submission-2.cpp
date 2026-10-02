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
    bool hasCycle(ListNode* head) {
        //two pointer, slow and fast (fast = cur->next->next)
#if 0
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow && fast->next && fast->next->next)
        {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)
                    return true;
        }
        return false;
#else
        unordered_set<ListNode *> s;
        ListNode *cur = head;
        while(cur)
        {
            if(s.find(cur) != s.end())
                return true;
            s.insert(cur);
            cur = cur->next;
        }
        return false;
#endif
    }
};
