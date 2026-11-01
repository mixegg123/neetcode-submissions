class StockSpanner {
stack<pair<int, int>> st; //<price, span>, span:: record the day be span at this price
int dropped = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        //vice verse is <=
        //monotonic stack decreasing
        if(st.empty() || st.top().first > price)
        {
            st.push({price, 1});
            return 1;
        }

        int span = 1;
        while(!st.empty() && st.top().first<=price)
        {
            span += st.top().second;
            st.pop();
            //record for next time
        }
        st.push({price, span});
        return span;
        //70, 80, 60, 75
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */