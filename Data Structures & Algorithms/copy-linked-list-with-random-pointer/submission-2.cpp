/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
#if 0
       //first iterall and creat a hashMap m
       // m<Node* ori, Node* copy>
       //so in secnod iter orignal and copy
       //when we access the ori's random, we can assign the update copy
       Node dummy(0);
       Node *orihead = head, *newhead = &dummy;
       unordered_map<Node*, Node*> m ;
       while(orihead)
       {
            newhead->next = new Node(orihead->val);
            m[orihead] = newhead->next;
            orihead = orihead->next;
            newhead = newhead->next;
       }
       //update random ptr
       orihead = head;
       newhead = dummy.next;
       while(orihead)
       {
            if(orihead->random != NULL)
            {
                newhead->random = m[orihead->random];
            } else
                newhead->random = NULL;
            orihead = orihead->next;
            newhead = newhead->next;
       }

       return dummy.next;
#else
    //using one hashmap to fix
    unordered_map<Node*, Node*> Copy;
    Copy[NULL] = NULL;
    Node* cur = head;
    //use this map, map<Original, new> to fulfill this new deepcopy
    while(cur)
    {
        Copy[cur] = new Node(cur->val);
        cur = cur->next;
    }

    Node dummy(0);
    Node *tmp = &dummy;
    cur = head;
    while(cur)
    {
        tmp->next = Copy[cur];
        tmp->next->random = Copy[cur->random];
        tmp = tmp->next;
        cur = cur->next;
    }
    return dummy.next;
#endif
    }
};
