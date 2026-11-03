class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       //greedy
        int sum = 0;
        int n  = gas.size();
        for(int i = 0;i<n;i++)
        {
            sum += (gas[i] - cost[i]);
        }

        if(sum < 0)
            return -1;

        int step = 0, rgas = 0;
        for(int i = 0;i<n;i++)
        {
            int start = i;
            int rgas = 0;
            while(rgas+gas[start] >= cost[start])
            {
                rgas += (gas[start] - cost[start]);
                start++;
                start = start %n;
                //printf("start:%d, rgas:%d\n",start,rgas);
                if(start == i)
                    return i;
            }
            i = start;
        }
        return -1;        
    }
};
