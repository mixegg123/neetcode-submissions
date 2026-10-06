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
                string tmp;
                tmp.push_back(board[i][j]);
                //start from first char match-ed
                if(tmp[0] == word[0])
                {
                    visited[i][j] = true;
                    if(dfs(board, i, j, tmp, visited, word))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &b, int x, int y, string &tmp, vector<vector<bool>> &visited, string word)
    {
        bool ret = false;

        if(tmp == word)
            return true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i = 0; i< 4;i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x<0 || new_x>=b.size() || new_y<0 ||new_y>=b[0].size() || tmp.size() >= word.size() || visited[new_x][new_y] == true)
                continue;
            tmp.push_back(b[new_x][new_y]);
            visited[new_x][new_y] = true;
            //printf("tmp: %s\n", tmp.c_str());
            ret = dfs(b, new_x, new_y, tmp, visited, word);
            if(ret)
                return true;
            tmp.pop_back();
            visited[new_x][new_y] = false;
        }
        return false;
    }
};
