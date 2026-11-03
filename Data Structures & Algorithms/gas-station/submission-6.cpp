class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       //greedy
/*
總量 ≥ 0 → 存的錢 ≥ 欠的債
前面每一段都是「先撐一陣子,最後才欠債」,所以欠債是一段一段慢慢累積的,最深的那個點就是所有債加起來
帶著的存款 ≥ 最深的債 → 過程中一定不會變負

不需要從頭走一圈
*/
        int sum = 0;
        int n  = gas.size();
        for(int i = 0;i<n;i++)
        {
            sum += (gas[i] - cost[i]);
        }

        if(sum < 0)
            //else >=0
            return -1;

        int total = 0, ans = 0;
        for(int i = 0;i<n;i++)
        {
            total += (gas[i] - cost[i]);

            if(total<0)
            {
                total = 0;
                ans = i + 1;
            }
        }
        return ans;        
    }
};
