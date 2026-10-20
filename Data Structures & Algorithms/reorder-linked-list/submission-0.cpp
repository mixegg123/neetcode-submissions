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
        //stack?
        ListNode dummy;
        stack<ListNode *> st;
        queue<ListNode *> q;
        ListNode *tmp = head;
        int n = 0, cnt = 0;;
        while(tmp)
        {
            st.push(tmp);
            q.push(tmp);
            tmp = tmp->next;
        }
        n = st.size();

        ListNode* node = &dummy;
        while(!q.empty() && !st.empty())
        {
            node->next = q.front();q.pop();
            node = node->next;
            if(++cnt == n) break;
            node->next = st.top();st.pop();
            node = node->next;
            if(++cnt == n ) break;
        }

        node->next = NULL;
    }
};
