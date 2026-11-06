class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(dfs(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &b, vector<vector<bool>> &v, int i, int j, const string &w, int index)
    {
        if(index == w.size())
            return true;

        if(i<0||i>=b.size() ||j<0 ||j>=b[0].size() ||v[i][j] ||b[i][j] != w[index])
            return false;
        v[i][j] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k = 0;k<4;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(dfs(b, v, nx, ny, w, index+1))
                return true;

        }
        v[i][j] = false;
        return false;
    }
};
