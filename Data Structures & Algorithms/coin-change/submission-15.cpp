class Solution {
public:
    int min_len = INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        //dp........
        vector<int> count(amount+1, amount+1);
        count[0] = 0;
        for(int i = 1; i<=amount; i++)
        {
            for(int coin: coins)
            {
                if(coin <= i)
                    count[i] = min(count[i], count[i-coin] + 1);
            }
        }
        return count[amount] <= amount?count[amount]:-1;
    }
};
