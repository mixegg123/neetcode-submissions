class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //n->f, h->e, r->n, e->r
        //h->e->r->n->f
        //z->o
        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, -1);
        queue<int> q;
        string result = "";
        int iUniqueWord = 0;

        // find Unique char and init a indegree
        for(string &word:words)
        {
            for(char &c : word)
            {
                if(indegree[c-'a'] == -1)
                {
                    indegree[c-'a'] = 0;
                    iUniqueWord++;
                }
            }
        }

        //create adj u->v
        for(int i = 0 ;i<words.size()-1; i++)
        {
            string &w1 = words[i];
            string &w2 = words[i+1];

            //w1 longer and prefix is same as w2, reject
            if(w1.size()>w2.size() && w1.compare(0, w2.size(), w2) == 0)
            return result;

            for(int j = 0;j<min(w1.size(), w2.size()); j++)
            {
                if(w1[j] != w2[j])
                {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    if(adj[u].find(v) == adj[u].end())
                    {
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    break;
                }
            }
        }

        //enqueue indegree is zero
        for(int i = 0;i<26;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        //topological sort
        while(!q.empty())
        {
            int u = q.front(); q.pop();
        
            //answer here, only add for indegree is zero
            result += (u+'a');
        
            for(int v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        //cannot reach unique word, has cycle (wrong order)
        return result.size() == iUniqueWord ? result: "";
    }
};
