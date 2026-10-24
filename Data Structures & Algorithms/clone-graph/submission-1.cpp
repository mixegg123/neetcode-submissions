/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //use hashMap and return first node..... (index-1)
        //BFS to create the clone
        if(!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> m; //<old, new>
        Node *newnode = new Node(node->val);
        m[node] = newnode;
        q.push(node);

        while(!q.empty())
        {
            Node *cur = q.front();q.pop();
            for(Node *tmp : cur->neighbors)
            {
                if(m.find(tmp) == m.end())
                {
                    m[tmp] = new Node(tmp->val);
                    q.push(tmp);
                }
                m[cur]->neighbors.push_back(m[tmp]);
            }
        }
        return m[node];
    }
};
