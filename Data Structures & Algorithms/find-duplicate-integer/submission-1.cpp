class Solution {
public:
    int findDuplicate(vector<int>& nums) {
#if 0
        unordered_set<int> s;

        for(int num : nums)
        {
            if(s.find(num) != s.end())
                return num;
            s.insert(num);
        }
        return 0;
#else
        //linkedlist, detect cycle and find the entry
        int slow = 0;
        int fast = 0;
//nums = [1,2,3,2,2]
//slow = 1, fast = 2
//slow = 2, fast = 3
//slow = 3, fast = 2
//slow = 2, fast = 2 -> met
//slow = 2, fast = 0
//slow = 3, fast = 1
//slow = 2, fast = 2 -> bingo

//step 1. find the meet point
//step 2. one back to orgin, start from start-point and met-point respectively
//step 3. meet point in step 2 is answer..
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
            {
                int slow2 = 0;
                while(slow != slow2)
                {
                    slow = nums[slow];
                    slow2 = nums[slow2];
                }
                return slow;
            }
        }
        return 0;
#endif
    }
};
