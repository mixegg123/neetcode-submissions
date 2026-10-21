class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //a BFS or DFS start from corner first row/last row, first/last col
        //for(int  = 0; i<4;i++)
        int m = board.size();
        int n = board[0].size();
        //vector<vector<bool>> visited(m, vector<bool>(n, false));
        {
            //first row
            for(int j = 0;j<n;j++)
            {
                //i=0
                dfs(board, 0, j);
            }
            //last row
            for(int j = 0;j<n;j++)
            {
                //i=m-1
                dfs(board, m-1, j);
            }

            //firt col
            for(int i = 1;i<m-1;i++)
            {
                //j=0
                dfs(board, i, 0);
            }

            //last col
            for(int i = 1;i<m-1;i++)
            {
                //j=n-1
                dfs(board, i, n-1);
            }
        }

        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }

    void dfs(vector<vector<char>> &b, int x, int y)
    {
        if(b[x][y] != 'O')
            return;        
        b[x][y] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || nx>=b.size() || ny<0 || ny>=b[0].size()
            || b[nx][ny] == '#')
                continue;

            dfs(b, nx, ny);
        }
    }
};
