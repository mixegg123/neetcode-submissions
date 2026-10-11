class Solution {
public:
    int maxArea(vector<int>& heights) {
        //h*(l-r)
        //two pointer
        int r = heights.size()-1;
        int l = 0, best = 0;

        while(l<r)
        {
            int h = min(heights[l], heights[r]);
            best = max(best, h*(r-l));

            if(heights[l]<=heights[r])
            {
                l++;
            }
            else
                r--;
        }
        return best;
    }
};
