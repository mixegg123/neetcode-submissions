class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> result;
        //bucket[i] = j, i is frequency, j is num
        // and still need a map
        unordered_map<int, int> m;
        //bucket[x][y]: x is count, y is which num happen x times
        vector<vector<int>> bucket(n+1);
        for(const int num : nums)
            m[num]++;
        for(auto &data : m)
            bucket[data.second].push_back(data.first);
        //for max to 0
        for(int i = n; i>=0 ; i--)
        {
            for(int num : bucket[i])
                result.push_back(num);
            if(result.size()>=k)
                return result;
        }
        return result;
    }
};
