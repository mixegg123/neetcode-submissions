class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num : nums)
            s.insert(num);
        
        int ans = 0;
        for(auto num : s)
        {
            if(s.find(num-1) == s.end())
            {
                int cnt = 1, tmp = num;
                while(s.find(++tmp) != s.end())
                {
                    cnt++;
                    //we only count for num-1, so O(n)                    //s.erase(tmp);
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
