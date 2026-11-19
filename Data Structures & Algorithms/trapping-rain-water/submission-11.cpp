class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;//monotonic decreasing w/ index

        int ans = 0;
        for(int r = 0 ; r < height.size(); r++)
        {
            while(!st.empty() && height[st.top()] < height[r])
            {
                int b = st.top(); st.pop();

                //no left wall
                if(st.empty())
                    break;

                int h = min(height[r], height[st.top()]) - height[b];
                int l = st.top();
                ans += (h * (r-l-1));
            }
            st.push(r);
        }
        return ans;
    }
};
