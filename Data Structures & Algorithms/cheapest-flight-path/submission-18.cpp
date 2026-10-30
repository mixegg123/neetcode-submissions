class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman-ford
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0;i<=k;i++)
        {
            vector<int> tmp = dist;
            for(auto &flight : flights)
            {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                
                if(dist[u] == INT_MAX) continue;
                
                //update v only
                tmp[v] = min(tmp[v], dist[u]+w);
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? - 1: dist[dst];
    }
};
