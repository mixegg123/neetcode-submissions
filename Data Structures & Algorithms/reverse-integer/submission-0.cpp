class Solution {
public:
    int reverse(int x) {
#if 0//hint

#else
        stack<int> st;
        st.push(x%10);

        int n = st.size();
        long ans = 0;
        if((long)x > INT_MAX || (long) x <INT_MIN)
            return 0;
        while(x)
        {
            ans *=10;
            int tmp = x%10;
            x = x/10;
            
            ans+=tmp;
            if(x &&(ans > INT_MAX/10 || ans < INT_MIN/10))
                return 0;
        }
        return ans;
#endif
    }
};
