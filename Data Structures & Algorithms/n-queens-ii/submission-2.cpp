class Solution {
public:
    vector<bool> col;
    vector<bool> rdiag; //r-c (shift n-1 to avoid negative index)
    vector<bool> ldiag; //r+c
    int totalNQueens(int n) {
        col.resize(n, false);
        rdiag.resize(2*n-1, false);
        ldiag.resize(2*n-1, false);
        int ans = 0;

        //0 is for row
        dfs(n, 0, ans);
        return ans;
    }

    void dfs(int n, int r, int &ans)
    {
        if(r == n)
        {
            ans++;
            return;
        }

        for(int c = 0; c<n;c++)
        {
            if(col[c] || rdiag[r-c+n-1] || ldiag[r+c])
                continue;
            col[c] = true;
            rdiag[r-c+n-1] = true;
            ldiag[r+c] = true;
            
            dfs(n, r+1, ans);
            
            ldiag[r+c] = false;
            rdiag[r-c+n-1] = false;
            col[c] = false;
        }
    }
};