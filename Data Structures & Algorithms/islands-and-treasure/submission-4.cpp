class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //從0出發的BFS.... nice
        queue<pair<int,int>> q; //<x, y>
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [x, y] = q.front(); q.pop();

            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0||nx>=grid.size()||ny<0||ny>=grid[0].size()||grid[nx][ny] == -1 || grid[nx][ny] != INT_MAX)
                continue;

                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return;
    }
};
