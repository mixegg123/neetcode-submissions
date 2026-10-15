class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
#if 1
    //2d
    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> ROW(m, false), COL(n, false);

    for(int i = 0; i<m; i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(matrix[i][j] == 0)
            {
                ROW[i] = true;
                COL[j] = true;
            }
        }
    }

    for(int i = 0; i<m; i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(ROW[i] || COL[j])
                matrix[i][j] = 0;
        }
    }

#else
    //1d
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i<m; i++)
    {
        for(int j = 0;j<n;j++)
        {
             if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }          
        }
    }

    for(int i = 0; i<m; i++)
    {
        for(int j = 0;j<n;j++)
        {
             if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }          
        }
    }
#endif
    }
};
