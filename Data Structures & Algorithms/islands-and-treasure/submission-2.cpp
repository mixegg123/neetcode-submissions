class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //dfs
        //we shall start from zero? no, if value already be small, skp
        int m = grid.size();
        int n = grid[0].size();
#if 0//dfs fail on time Limit
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                    dfs(grid, i, j, 0);
            }
        return;
#else
        queue<pair<int, int>> q;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [x, y] = q.front();q.pop();

            for(int i = 0;i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >=grid.size() || ny>=grid[0].size() ||grid[nx][ny] == -1
                || grid[nx][ny] != INT_MAX)
                    continue;
                
                grid[nx][ny] = grid[x][y]+1;
                q.push({nx, ny});
            }
        }
#endif
    }

    void dfs(vector<vector<int>> &g, int x, int y, int dist)
    {
        g[x][y] = dist;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >=g.size() || ny>=g[0].size() ||g[nx][ny] == -1
            || g[nx][ny] <= g[x][y])
                continue;
            dfs(g, nx, ny, dist+1);
        }
    }
};
