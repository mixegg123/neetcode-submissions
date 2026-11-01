class StockSpanner {
stack<int> st;
int dropped = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        //vice verse is <=
        //monotonic stack decreasing
        if(st.empty() || st.top() > price)
        {
            st.push(price);
            return 1;
        }
        
        int cnt = 1;
        stack<int> tmp = st;
        while(!tmp.empty() && tmp.top()<=price)
        {
            tmp.pop();
            cnt++;
            //record for next time
        }
        st.push(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */