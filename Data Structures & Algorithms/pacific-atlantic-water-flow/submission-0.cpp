class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        //dfs  
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        //first row
        for(int i = 0; i<n;i++)
            dfs(heights, 0, i, pacific);
        //last row
        for(int i = 0; i<n; i++)
            dfs(heights, m-1, i, atlantic);
        //first column
        for(int i = 0; i<m; i++)
            dfs(heights, i, 0, pacific);
        //last column
        for(int i = 0; i<m; i++)
            dfs(heights, i, n-1, atlantic);
        
        //sort the answer
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(pacific[i][j] & atlantic[i][j])
                    res.push_back({i,j});
        return res;
    }

    void dfs(vector<vector<int>> &h, int x, int y, vector<vector<bool>> &visited)
    {
        
        visited[x][y] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int i = 0; i<4; i++)
        {
            //board boundary must be <=
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=h.size() || ny<0 || ny>=h[0].size() || h[x][y] > h[nx][ny] ||  visited[nx][ny])
                continue;

            dfs(h, nx, ny, visited);
        }
    }
};
