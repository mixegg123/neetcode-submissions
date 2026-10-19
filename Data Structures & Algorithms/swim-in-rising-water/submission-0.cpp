class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //minimum amount of time, Dijkstra?
        //u->v is w, w is grid[i][j] is from 0 to here time
        //..
        //MinHeap <dist, i, j> ?
        //dp[n-1][n-1] is result

        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        pq.push({dp[0][0], 0, 0});

        while(!pq.empty())
        {
            auto [w, x, y] = pq.top();pq.pop();
            if(w > dp[x][y]) continue;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n)
                    continue;
                int cost = max(dp[x][y], grid[nx][ny]);
                if(cost < dp[nx][ny])
                {
                    dp[nx][ny] = cost;
                    pq.push({cost, nx, ny});
                }
            }
        }
        return dp[n-1][n-1];
    }
};
