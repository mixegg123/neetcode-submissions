class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //priority-heap, and maxHeap (in-default)
        //for insert all items to queue
        //while (queue.size > 1)
        //return top if remain, or 0 if q is empty
        priority_queue<int> q;
        for(const int stone : stones)
            q.push(stone);

        while(q.size() > 1)
        {
            int x = q.top();q.pop();
            int y = q.top();q.pop();
            int res = abs(x-y);
            if(res)
                q.push(res);
        }

        return q.empty() ? 0 : q.top();
    }
};
