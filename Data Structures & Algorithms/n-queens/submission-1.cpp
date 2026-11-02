class Solution {
public:
    vector<bool> col;
    //r+c: left-down, size: 2n-1
    vector<bool> lslash;
    //r-c: right-down, size: 2n-1 (-(n-1)~n-1) n-1 ~ -n+1
    vector<bool> rslash;

    vector<vector<string>> solveNQueens(int n) {
        //three array to record col, left-slash and right-slash
        col.resize(n, false);
        lslash.resize(2*n-1, false);
        rslash.resize(2*n-1, false);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        dfs(n, 0, board, ans);
        return ans;
    }

    void dfs(int n, int r, vector<string> &board, vector<vector<string>> &ans)
    {
        if(r == n)
        {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c<n;c++)
        {
            if(col[c] || lslash[r+c] || rslash[r-c+n-1])
                continue;
                
            col[c] = true;
            lslash[r+c] = true;
            rslash[r-c + n-1] = true;
            board[r][c] = 'Q';

            dfs(n, r+1, board, ans);

            board[r][c] = '.';
            lslash[r+c] = false;
            rslash[r-c + n-1] = false;
            col[c] = false;
        }
    }
};
