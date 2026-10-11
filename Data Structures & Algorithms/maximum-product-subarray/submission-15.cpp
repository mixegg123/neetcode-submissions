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
            productMax = productMax*num;
            productMin = productMin*num;
            int updateMax = max({productMax, productMin, num});
            int updateMin = min({productMax, productMin, num});

            productMax = updateMax;
            productMin = updateMin;

            best  = max({best, updateMax});
        }
        return best;
    }
};
