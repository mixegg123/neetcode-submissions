class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search
        int l = 1, r = 0, ans = 0;
        for(int pile : piles)
            r = max(r, pile);

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            long long consume = 0;
            for(int pile : piles)
                consume += ((pile+mid-1)/mid);
            
            if(consume <= h)
            {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
