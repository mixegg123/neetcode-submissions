class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
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
    }
};
