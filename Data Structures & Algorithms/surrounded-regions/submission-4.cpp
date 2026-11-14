class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //1st/last row
        for(int j = 0;j<n;j++)
        {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        //1ast last column 
        for(int i = 0;i<m;i++)
        {
            dfs(board, i, 0);    
            dfs(board, i, n-1);
        }      

        //final update, '#' -> 'O' (since # is dirty by boards boundary)
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
 
    }

    void dfs(vector<vector<char>> &b, int x, int y)
    {
        int m = b.size();
        int n = b[0].size();

        if(x<0||x>=m||y<0||y>=n||b[x][y] == 'X'||b[x][y] == '#')
            return;

        b[x][y] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            dfs(b, x+dx[i], y+dy[i]);
        }
    }
};
