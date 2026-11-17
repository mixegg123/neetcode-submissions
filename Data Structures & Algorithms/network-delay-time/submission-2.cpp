class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Dijkstra
        using P = pair<int, int>;
        vector<int> dist(n+1, INT_MAX);
        vector<vector<P>> adj(n+1);

        for(auto e : times)
        {
            //[u] -> <v, time>
            adj[e[0]].push_back({e[2], e[1]});
        }

        //<cost, u>
        priority_queue<P, vector<P>, greater<P>> pq;

        //original k
        dist[k] = dist[0] = 0;
        pq.push({0, k});
        //adj[u]->v
        //priority_queue
        while(!pq.empty())
        {
            auto [cost, u] = pq.top(); pq.pop();

            if(cost > dist[u]) continue;

            for(auto [time, v] :adj[u])
            {
                if(dist[v] > dist[u] + time)
                {
                    dist[v] = dist[u] + time;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    
    }
};
