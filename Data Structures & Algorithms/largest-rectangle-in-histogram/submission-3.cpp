class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;//monotonic stack increasing
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(),0);
        int ans = 0;
        for(int r = 0; r<heights.size();r++)
        {
            while(!st.empty() && heights[st.top()] > heights[r])
            {
                int h = heights[st.top()];st.pop();
                int l = st.top();
                ans = max(ans, (r-l-1)*h);
            }
            st.push(r);
        }

        return ans;
    }
};
