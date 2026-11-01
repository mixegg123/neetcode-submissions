class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       //topological sort
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(auto pre : prerequisites)
        {
            //u->v: [1] -> [0]
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        for(int i = 0; i<numCourses; i++)
        {
            if(!indegree[i])
                q.push(i);
        }

        //indgree == 0, push to ans
        while(!q.empty())
        {
            int u = q.front();q.pop();
            ans.push_back(u);
            for(auto v : adj[u])
            {
                if(--indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return ans.size() == numCourses?ans: vector<int>{};
    }
};
