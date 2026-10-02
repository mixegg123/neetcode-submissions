class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Dijkstra
        //標準 Dijkstra 只看「誰花錢少」，忽略了「花錢多一點的人，可能節省了轉機次數，後面還有救」。
        //iterate k+1 times
        //prices[n:src][k:stops]
#if 0//2d
        vector<vector<int>> prices(n, vector<int>(k+2, INT_MAX));
        //miniHeap
        //tuple<當前總 Cost, 當前節點 u, 已經搭了幾班飛機 stops>
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        prices[src][0] = 0;
        //u, and {prices, v}
        vector<vector<pair<int, int>>> adj(n);
        for(auto &f : flights)
        {
            adj[f[0]].push_back({f[2],f[1]});
        }
        //start from src
        //{cost, u, stops}
        q.push({0, src, 0});
        while(!q.empty())
        {
            auto [cost, u, stops] = q.top();
            q.pop();

            //in minHeap, it must cost few one
            if(u == dst) return cost;
            //cannot fly anymore
            if(stops == k+1) continue;
            
            for( auto &[w, v] : adj[u])
            {
                int next_cost = prices[u][stops] + w;
                int next_stop = stops+1;
                if( next_cost < prices[v][next_stop])
                {
                    prices[v][next_stop] = next_cost;
                    q.push({next_cost,v, next_stop});
                }
            }
        }
        return -1;
#else //1d
    vector<int> prices(n, INT_MAX);
    prices[src] = 0;

    for(int i = 0; i<=k; i++)
    {
        vector<int> tmpPrice = prices;

        for(auto &f: flights)
        {
            int u = f[0];
            int v = f[1];
            int p = f[2];
            if(prices[u] != INT_MAX) // old 
            {
                tmpPrice[v] = min(tmpPrice[v], prices[u] + p); //update cache
            }
        }
        prices = tmpPrice; //update cahce
    }
    return prices[dst] != INT_MAX ? prices[dst]: - 1;

#endif
    }
};
