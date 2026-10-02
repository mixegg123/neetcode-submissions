class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //upper bound of k is maximum size of a pile, so it can eat all in piles.size() time
        //brute force 
        int ans = 0;
        int largetPile = 0;

        for(const int pile : piles)
            largetPile = max(largetPile, pile);
        //printf("l:%d\n", largetPile);

#if 0//brute force
        for(int i = 1; i<=largetPile; i++ )
        {
            int eattime = 0;
            for(int j = 0;j<piles.size();j++)
            {
                eattime += ceil((double)piles[j]/i);
                //printf("eattime: %d\n", eattime);
            }
            if(eattime <=h)
            {
                ans = i;
                break;
            }
        }
        return ans;
#else
    //binart search
    int l = 1, r = largetPile;
    while(l<=r)
    {
        int mid = l + (r-l)/2;

        int eattime = 0;
        for(int j = 0;j<piles.size();j++)
            eattime += ceil((double)piles[j]/mid);
        //eattime <= target
        //[red, red, red, green, green,..], find first green
        if (eattime <= h){
            //minimun so this is condition
            ans = mid;
            r = mid - 1;
        } else
        {   
            l = mid + 1;
        }
    }
    return ans;
#endif
    }
};
