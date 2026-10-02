class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;

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
    }
};
