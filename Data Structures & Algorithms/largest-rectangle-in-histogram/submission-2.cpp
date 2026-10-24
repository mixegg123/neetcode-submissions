class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;//monotonic stack increasing
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        int ans = 0;
        for(int r = 0; r<heights.size();r++)
        {
            while(!st.empty() && heights[st.top()] > heights[r])
            {
                int h = heights[st.top()];st.pop();
                //printf("h:%d, r:%d, heights[r]:%d\n",h, r, heights[r]);
                int l = st.top();
                ans = max(ans, (r-l-1)*h);
                //printf("l:%d, ans:%d\n",l, ans);
            }
            st.push(r);
        }

        return ans;
    }
};
