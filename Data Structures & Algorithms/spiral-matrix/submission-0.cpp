class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0, right = n -1, left = 0, bottom = m-1;
/*
[1, 2, 3 4]
[5, 6, 7, 8]
[9, 10, 11, 12]
*/
        while(top <= bottom && left <= right)
        {
            //top
            int i = 0;
            for(i = left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;

            //right
            for(i = top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;


            //!! intermediate check
            if(top > bottom || left > right)
                break;
    
            //bottom
            for(i = right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            //left
            for(i = bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
            left++;

            //above will check in while condition
        }
        return ans;
    }
};
