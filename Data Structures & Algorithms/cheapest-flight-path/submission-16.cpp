class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman-ford
        vector<int> dp(n, INT_MAX);
        dp[src] = 0;
        for(int i = 0;i<=k;i++)
        {
            vector<int> tmp = dp;
            for(auto &flight : flights)
            {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                
                if(dp[u] == INT_MAX) continue;
                
                //update v only
                tmp[v] = min(tmp[v], dp[u]+w);
            }
            dp = tmp;
        }
        return dp[dst] == INT_MAX ? - 1: dp[dst];
    }
};
