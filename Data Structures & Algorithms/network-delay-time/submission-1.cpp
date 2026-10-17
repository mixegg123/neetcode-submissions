class Solution {
//{distance, node}
using PII = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            //dijkstra

            vector<vector<pair<int,int>>> adj(n+1); //adj[u] = [{v, w}]
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;//mini-heap <distance, node>
            vector<int> dist(n+1, INT_MAX);

            for(auto time: times)
            {
                adj[time[0]].push_back({time[1], time[2]});
            }

            //start from k, so itself is zero
            dist[k] = 0;
            pq.push({0, k});

            while(!pq.empty())
            {
                    auto [d, u] = pq.top();pq.pop();
/*
結論:因為 dist[u] 在 push 進 heap 的那一刻就已經更新過了。pop 出來的 d 只可能 ≥ dist[u],不可能更小,所以沒有東西需要更新。
*/
                    if(d > dist[u]) continue;

                    for(auto &[v, w] : adj[u])
                    {
                        if(dist[v] > w + d)
                        {
                            dist[v] = w + d;
                            pq.push({dist[v], v});
                        }
                    }
            }
            int ans = *max_element(dist.begin()+1, dist.end());
            return ans == INT_MAX ? -1: ans;
    }
};
