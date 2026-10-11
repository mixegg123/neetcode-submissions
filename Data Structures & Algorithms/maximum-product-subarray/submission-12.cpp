class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //subarry, it could be left/right pointer way, not dynamic program (since it's not subsequence)
        //[-2, -4, -3, 5]
        int l = 0, best = INT_MIN, productMax=1, productMin=1;
        //printf("size: %d\n", nums.size());
        //for(int r = 0; r<nums.size();r++)
        for(const int num : nums)
        {
            int temp1 = productMax*num;
            int temp2 = productMin*num;
            productMax = max({temp1, temp2, num});
            productMin = min({temp1, temp2, num});

            best  = max({best, productMax, productMin});
        }
        return best;
    }
};
