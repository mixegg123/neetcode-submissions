class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ans = 0;
        int carry = 0;
        //int shift = 0;
        for(int i = 0;i<32; i++)
        {
/*
補數的設計目的,就是讓加法器不用管正負號。硬體只有一套加法器,有號、無號共用,所以你全程用 unsigned 算,最後轉回 int 就對了。
*/
            //XOR
            unsigned int a_bits = a&1;
            unsigned int b_bits = b&1;
            ans |= (a_bits^b_bits^carry)<<i;
            // if cannot use +
            #if 0
            carry = (a_bits+b_bits+carry)>=2?1:0;
            #else
            //a, b, carry
            //1 0 1, 1 1 1, 0 0 1, 0 0 0
            carry = carry &(a_bits^b_bits) || a_bits&b_bits;
            #endif
            a = a>>1;
            b = b>>1;
        }

        return (int) ans;
    }
};
