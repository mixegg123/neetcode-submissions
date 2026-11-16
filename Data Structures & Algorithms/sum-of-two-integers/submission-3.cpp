class Solution {
public:
    int getSum(int a, int b) {
        //ans and carry how to calculate...
        int ans = 0, carry = 0;
        for(int i = 0 ; i<32;i++)
        {
            int a_bit = a&1;
            int b_bit = b&1;

            ans |= ((a_bit^b_bit^carry)<<i);

            carry = (a_bit & b_bit) || (a_bit^b_bit)&carry;

            a>>=1;
            b>>=1;
        }

        return ans;
    }
};
