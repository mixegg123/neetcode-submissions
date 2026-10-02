class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //monotonic stack decreasing
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;

        for(int i = 0; i <temperatures.size(); i++)
        {
                while(!st.empty() && temperatures[st.top()] < temperatures[i])
                {
                    int cur = st.top(); st.pop();
                    result[cur] = i - cur;
                }
                st.push(i);
        }
        return result;
    }
};
