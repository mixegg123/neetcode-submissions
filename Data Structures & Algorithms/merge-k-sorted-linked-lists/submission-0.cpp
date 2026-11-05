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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        while(lists.size()>=2)
        {
            vector<ListNode*> temp;
            for(int i = 0;i<lists.size(); i+=2)
            {
                if(i == lists.size()- 1)
                {
                    temp.push_back(lists[i]);
                } else
                {
                    ListNode* updateList = merge(lists[i], lists[i+1]);
                    temp.push_back(updateList);
                }

            }
            lists = temp;
        }

        return lists.empty()?nullptr:lists[0];
    }

    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *cur = &dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            } else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        ListNode *tmp = (l1) ?l1:l2;
        while(tmp) 
        {
            cur->next = tmp;
            tmp = tmp->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
