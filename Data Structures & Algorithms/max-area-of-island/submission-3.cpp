class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //need visited (by write to zero)
        //DFS
        int m = grid.size();
        int n = grid[0].size();
        ans = 0;
        for(int i = 0;i<m;i++)
            for(int j =0;j<n;j++)
            {
                if(grid[i][j] ==1)
                {
                    int cnt = 1;
                    dfs(grid, i, j, cnt);
                }
            }
        return ans;
    }

    void dfs(vector<vector<int>> &g, int x ,int y, int &cnt)
    {
        ans = max(ans, cnt);
        g[x][y] = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

             if(nx<0 || nx>=g.size()||ny<0||ny>=g[0].size() || g[nx][ny] !=1)
                continue;
            cnt++;
            dfs(g, nx, ny, cnt);
        }
    }
private:
    int ans;
};
