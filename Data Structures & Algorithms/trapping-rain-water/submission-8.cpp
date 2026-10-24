class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;//monotonic decreasing w/ index

        int ans = 0;
        for(int r = 0 ; r < height.size(); r++)
        {
            while(!st.empty() && height[st.top()] < height[r])
            {
                int cur = 0, l = 0;
                int b = st.top(); st.pop();

                if(st.empty())
                    break;
                l = st.top();
                int h = min(height[l],height[r]) -height[b];
                cur = h*(r-l - 1);
                ans += cur;
            }
            st.push(r);
        }
        return ans;
    }
};
