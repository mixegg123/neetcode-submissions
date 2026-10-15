class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
#if 0
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
/*
用例子看會出什麼錯
1 1 0
1 1 1
1 1 1

正確答案:第 0 列全清,第 2 行全清。

0 0 0
1 1 0
1 1 0
*/
    //[0][0]要額外record

    int m = matrix.size();
    int n = matrix[0].size();
    bool frowZero = false, fcolZero = false;

    for(int j = 0; j<n;j++)
        if(matrix[0][j] == 0)
            frowZero = true;

    for(int i = 0;i<m;i++)
        if(matrix[i][0] == 0)
            fcolZero = true;

    for(int i = 1; i<m; i++)
    {
        for(int j = 1;j<n;j++)
        {
             if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }          
        }
    }

    for(int i = 1; i<m; i++)
    {   
        for(int j = 1;j<n;j++)
        {
            if ( matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }          
        }
    }
    if(frowZero)
        for(int j = 0;j<n;j++)
            matrix[0][j] = 0;
    if(fcolZero)
        for(int i = 0;i<m;i++)
            matrix[i][0] = 0;
#endif
    }
};
