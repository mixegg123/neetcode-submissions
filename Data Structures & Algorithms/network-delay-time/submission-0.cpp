class Solution {
//{distance, node}
using PII = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Dijkstra
        vector<int> time(n+1, INT_MAX);
        //adj {distance, node}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        //adj
        vector<vector<PII>> adj(n+1);
        for(auto &t: times)
            adj[t[0]].push_back({t[2], t[1]});

        time[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            if(d > time[u]) continue;

            for(auto &[w, v] : adj[u])
            {
 
                if(time[v] > time[u] + w)
                {
                    time[v] = time[u] + w;
                    pq.push({time[v], v});
                }
            }
        }

        //minimal time (so it's maximum time across time[])
        int ans = 0;
        for(int i = 1; i<n+1; i++)
            ans = max(ans, time[i]);
        return ans == INT_MAX?-1:ans;
    }
};
