class Solution {
public:
    vector<bool> col;
    vector<bool> rdiag;
    vector<bool> ldiag;
    int totalNQueens(int n) {
        //col
        //r+c
        //r-c
        col.resize(n, false);
        //r-c
        rdiag.resize(2*n-1, false);
        //r+c
        ldiag.resize(2*n-1, false);
        
        int ans = 0;
        dfs(n , 0, ans);
        return ans;
    }

    void dfs(int n, int start, int &ans)
    {
        if(start == n)
        {
            ans++;
            return;
        }

        for(int c = 0;c<n;c++)
        {
            if(col[c] || rdiag[start+c] ||ldiag[start-c+n-1])
                continue;
            
            col[c] = true;
            rdiag[start+c] = true;
            ldiag[start-c+n-1] = true;
            dfs(n, start+1, ans);
            col[c] = false;
            rdiag[start+c] = false;
            ldiag[start-c+n-1] = false;            
        }
    }
};