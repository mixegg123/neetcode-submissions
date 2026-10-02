class Solution {
public:
    int trap(vector<int>& height) {
        //two point, get lh, and rh, then navigate again to get each sum of index?
        //monotonic stack decreasing
        stack<int> st;
        int sum = 0;
        for(int r = 0; r<height.size(); r++)
        {
            while(!st.empty() && height[st.top()] < height[r])
            {
                int bottom = st.top();
                st.pop();

                //no left wall
                if(st.empty())
                    break;
                
                int l = st.top();
                int cur = min(height[l], height[r]) - height[bottom];
                cur = cur * (r - l - 1);
                //printf("l:%d, r:%d, cur:%d sum:%d\n", l, r, cur, sum);
                sum += cur;
            }
            st.push(r);
        }
        return sum;
    }
};
