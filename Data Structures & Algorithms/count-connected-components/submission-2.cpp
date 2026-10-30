class Solution {
public:
    vector<int> p;
    int countComponents(int n, vector<vector<int>>& edges) {
        //DSU
        vector<vector<int>> adj(n);
        int ans = n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        for(auto &edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int u = 0; u<adj.size();u++)
        {
            for(int v : adj[u])
                if(unite(u,v)) ans--;
        }
        return ans;
    }

    int find(int node)
    {
        return node == p[node] ?
            node : p[node]=find(p[node]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b)
            return false;
        
        p[a] = b;

        return true;
    }
};
