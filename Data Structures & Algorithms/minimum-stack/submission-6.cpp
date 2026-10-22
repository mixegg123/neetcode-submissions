class MinStack {
public:
//a MinHeap plus a stack...
    //ext, only keep the smallest value for current stack index i..
    stack<int> ext;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
//每一層都記著「從底部到這一層的最小值」,所以 pop 時兩邊一起 pop,最小值就自動退回上一個狀態。

        if(ext.empty())
            ext.push(val);
        else
            ext.push(min(val, ext.top()));
    }
    
    void pop() {
        st.pop();
        ext.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ext.top();
    }
};
