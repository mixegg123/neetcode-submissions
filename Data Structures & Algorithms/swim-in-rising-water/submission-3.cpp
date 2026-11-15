class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //Dijkstra
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> miniHeap;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        //T is <time/dp, x, y>
        miniHeap.push({dp[0][0], 0, 0});
        
        while(!miniHeap.empty())
        {
            auto [cost, x, y] = miniHeap.top(); miniHeap.pop();

            //if cost larger than dp, stale and skip
            if(cost > dp[x][y]) continue;

            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0||nx>=m||ny<0||ny>=n)
                    continue;
                
                //inherit max from path
                cost = max(dp[x][y], grid[nx][ny]);
                if(dp[nx][ny] > cost)
                {
                    dp[nx][ny] = cost;
                    miniHeap.push({dp[nx][ny], nx, ny});
                }
            }
        }

        return dp[m-1][n-1];
    }
};
