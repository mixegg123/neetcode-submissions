class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //bfs, visited, minH, vector<int> result(n)-->(root, h)
        vector<int> ans;
        vector<int> result(n, 0);
        queue<int> q;
        int minH = INT_MAX;

        vector<vector<int>> adj(n);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int root = 0;root<n;root++)
        {
            q.push(root);
            int height = 0;
            vector<bool> visited(n, false);
            visited[root] = true;
            while(!q.empty())
            {
                int size = q.size();
                height++;
                for(int j = 0;j<size;j++)
                {
                    int u = q.front();q.pop();
                    for(auto v : adj[u])
                    {
                        if(!visited[v])
                        {
                            q.push(v);
                            visited[v] = true;
                        }
                        
                    }
                }
            }
            minH = min(minH, height);
            result[root] = height;
        }

        //given ans
        for(int i = 0;i<result.size();i++)
        {
            if(result[i] == minH)
                ans.push_back(i);
        }
        return ans;
    }
};