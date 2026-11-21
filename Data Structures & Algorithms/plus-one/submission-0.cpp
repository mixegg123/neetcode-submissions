class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n, 0);
        int carry = 1;

        for(int i = n-1;i>=0;i--)
        {
            int tmp = digits[i] + carry;
            carry = tmp/10;
            tmp = tmp %10;
            ans[i] = tmp;
        }

        if(carry)
            ans.insert(ans.begin(), 1);

        return ans;
    }
};
