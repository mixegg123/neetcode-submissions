class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transport and reverse the row
        int m = matrix.size();
        int n = matrix[0].size();

        //Transpose (only touch right upper)
        for(int r = 0; r<m; r++)
            for(int c = r+1;c<n;c++) //key is r+1
            {
                swap(matrix[r][c], matrix[c][r]);
            }

        //Reverse
        for(int i = 0;i<m;i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
