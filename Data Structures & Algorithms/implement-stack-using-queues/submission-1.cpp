class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.empty())
        {
            q.push(x);
            return;
        }

        vector<int> tmp;
        while(!q.empty())
        {
            tmp.push_back(q.front());q.pop();
        }
        //[1, 2] -> [2 1]
        //3 [2, 1] -> v [2, 1] -> [3, 2, 1]
        //4 [3, 2, 1] -> v [3, 2, 1] -> [4, 3, 2, 1]
        q.push(x);
        for(int i = 0;i<tmp.size();i++)
            q.push(tmp[i]);

        return;
    }
    
    int pop() {
        int tmp = q.front();q.pop();
        return tmp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */