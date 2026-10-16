class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //maxheap: priority_queue<<int> <freq>
        //queue<<int,int>> <next_available-time, task freq>
        priority_queue<int> pq; //<freq>
        queue<pair<int, int>> q; //<next avaialble time, freq>
        int nums[26] = {0};

        //pq is task can executing, waiting
        //q is in cool-down, waiting..
        for(int i = 0;i<tasks.size(); i++)
            nums[tasks[i]-'A']++;

        for(int i = 0;i<26;i++)
        {
            if(nums[i] !=0)
                pq.push(nums[i]);
        }

        int time = 0;
        while(!pq.empty() || !q.empty())
        {
            int task;
            time++;
            if(!pq.empty())
            {
                task = pq.top();
                pq.pop();
                task--;
                if(task != 0)
                    q.push({time+n, task});
            }

            while(!q.empty() && q.front().first <= time)
            {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};
