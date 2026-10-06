class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //it must has outer and inner loop
        int m = board.size();
        int n = board[0].size();
        bool ret = false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                //start from first char match-ed
                //TO-DO, not using tmp, using i as word index
                if(dfs(board, i, j, visited, word, 0))
                    return true;

            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &b, int x, int y, vector<vector<bool>> &visited, string word, int i)
    {
        bool ret = false;

        if(i == word.size())
            return true;

        if(x<0 || x>=b.size()||y<0||y>=b[0].size()||visited[x][y]||b[x][y]!=word[i])
            return false;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int k = 0; k< 4;k++)
        {
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            visited[x][y] = true;
            ret = dfs(b, new_x, new_y, visited, word, i+1);
            if(ret)
                return true;

            visited[x][y] = false;
        }
        return false;
    }
};
