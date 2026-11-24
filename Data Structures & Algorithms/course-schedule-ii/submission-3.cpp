class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       //topological sort
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        //prerequisites[1] -> prerequisites[0]

        for(auto pre: prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int i = 0;i<numCourses;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();q.pop();

            for(auto v : adj[u])
            {
                --indegree[v];
                if(!indegree[v])
                {
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }

        return ans.size() == numCourses?ans:vector<int>{};
    }
};
