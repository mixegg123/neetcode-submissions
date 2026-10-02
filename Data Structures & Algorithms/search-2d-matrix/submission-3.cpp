class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find the row, search the row
        
#if 1
        //magic solution, using mxn - 1....
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m*n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int val = matrix[mid/n][mid%n];
            //matrix[mid/n][mid%n];
            if(target == val)
                return true;
            if(target > val)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
#else
        while(l<r)
        {
            int mid = l + (r-l)/2;
            //l = 0, r= 3, mid = 1
            //l=0,r=1, mid = 0
            //l=0, r=0
            //printf("l:%d, r:%d, mid:%d\n", l, r, mid);
            if(matrix[mid][0] <= target)
                l = mid;
            else
                r = mid-1;
        }
        //printf("l:%d\n",l);

        //l is r and target
        int ll = 0, rr= matrix[0].size() - 1;
        while(ll<=rr)
        {
            int mid = ll + (rr-l)/2;
            if(matrix[l][mid] == target)
                return true;
            if(matrix[l][mid] <target)
                ll++;
            else
                rr--;
        }
        return false;
#endif
    }
};
