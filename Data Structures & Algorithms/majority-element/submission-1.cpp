class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //map<number, count>
        unordered_map<int, int> m;
        int n = nums.size()/2;

        for(int num : nums)
        {
            m[num]++;
            if(m[num]>n)
                return num;
        }
        return -1;
    }
};