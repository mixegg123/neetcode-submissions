class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //dfs + visited[m]][n] and for loop to calculate the num of Islands
        //row x col
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == '0')
                    continue;
                cnt++;
                dfs(grid, i, j);
            }
        }
        return cnt;

    }

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())
            return;
        if( grid[x][y] == '0') return;

        grid[x][y] = '0';

        for(int i=0;i<4;i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            dfs(grid, newX, newY);
        }
    }
};
