class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //memo + DFS
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& m, vector<vector<int>> &memo, int x, int y)
    {
        if(memo[x][y] > 0)
            return memo[x][y];

        int step = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||nx>=m.size()||ny<0||ny>=m[0].size() || m[x][y] >= m[nx][ny])
            continue;
            
            step = max(step, 1+dfs(m, memo, nx, ny));
        }

        memo[x][y] = step;
        return step;
    }
};
