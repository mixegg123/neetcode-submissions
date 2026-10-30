class Solution {
public:
    vector<int> p;
    int countComponents(int n, vector<vector<int>>& edges) {
        //DSU
        vector<vector<int>> adj(n);
        int ans = n;
        for(int i = 0;i<n;i++)
            p.push_back(i);
        for(auto &edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int u = 0; u<adj.size();u++)
        {
            for(int v : adj[u])
            {
                bool ret = unite(u,v);
                //printf("u:%d,v:%d,ret:%d ans:%d\n", u, v, ret, ans);
                if(!ret) continue;
                ans--;
            }
        }
        return ans;
    }

    int find(int node)
    {
        return node == p[node] ?
            node : p[node]=find(p[node]);
    }

    bool unite(int nodeA, int nodeB)
    {
        int root_A = find(nodeA);
        int root_B = find(nodeB);
        if(root_A == root_B)
            return false;
        
        p[root_B] = root_A;

        return true;
    }
};
