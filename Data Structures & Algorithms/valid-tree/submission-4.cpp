class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
#if 0
        //topological sort? (not DAG.. no)
        //dfs + visited
        // or bfs?
        sort(edges.begin(), edges.end());
        vector<vector<int>> adj(n);
        queue<int> q;
        unordered_set<int> visited;

        //edges number must (node number - 1)
        if(edges.size() != n-1)
            return false;
        for(auto &edge : edges)
        {
            //adj and bi-directional
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        //BFS
        q.push(0);
        visited.insert(0);
        while(!q.empty())
        {
            int node = q.front();q.pop();

            for(int neighbor:adj[node])
            {
                if(!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }

        }

        return visited.size()== n;
#else
    //dfs
    //bool validTree(int n, vector<vector<int>>& edges)
    //using dfs or bfs, need build a vector<vector<int>> adj(n)
    // tree shall be E = N - 1;
    int k = edges.size();
    if(k != n-1)
        return false;
    vector<vector<int>> adj(n);
    for(auto &edge : edges)
    {
        //undirected, bi-drection to push
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    //a set to record visited node
    unordered_set<int> s;
    s.insert(0);
    //start from zero
    dfs(adj, 0, s);

    return s.size() == n;
#endif
    }

    void dfs(vector<vector<int>> &adj, int node, unordered_set<int> &s)
    {
        for(auto u : adj[node])
        {
            if(!s.count(u))
            {
                s.insert(u);
                dfs(adj, u, s);
            }
        }
        return;
    }
};
