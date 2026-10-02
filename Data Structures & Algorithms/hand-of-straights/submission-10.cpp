class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
#if 0
        map<int, int> m;

        for(int h: hand)
            m[h]++;

        for(int i = 0; i <hand.size()/groupSize; i++)
        {
            int small = m.begin()->first;
            for(int j = small; j<=small+groupSize-1; j++)
            {
                if(m.find(j) != m.end())
                {
                    m[j]--;
                    if(!m[j])
                        m.erase(j);
                }
                else
                    return false;
            }

        }
        return true;
#else
        //use sort + unordered_map as solution by hint in this ticket
        unordered_map<int, int> count;
        
        for(int h : hand)
            count[h]++;
        sort(hand.begin(), hand.end());

        for(int h : hand)
        {
            if(count[h] == 0) continue;
            for(int j = h; j<=h+groupSize-1; j++)
            {
                if(count[j] == 0)
                    return false;
                count[j]--;
            }
        }
        return true;
    }
#endif
};
