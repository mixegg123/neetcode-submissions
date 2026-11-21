class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n, 0);
        int carry = 1;

        for(int i = n-1;i>=0;i--)
        {
#if 1
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
#else
            int tmp = digits[i] + carry;
            carry = tmp/10;
            tmp = tmp %10;
            ans[i] = tmp;
#endif
        }

        if(carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
