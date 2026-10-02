class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort
        //b->a
        int num = 0;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        //Kahn's algoritm, BFS
        queue<int> q;
        //update adj (understand the edge) and in degree for each node
        for(auto &e :prerequisites)
        {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        for(int i = 0; i<numCourses; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            num++;
            for(int i = 0; i< adj[course].size();i++)
            {
                indegree[adj[course][i]]--;
                if(!indegree[adj[course][i]])
                    q.push(adj[course][i]);
            }
        }

        return numCourses == num;
    }
};
