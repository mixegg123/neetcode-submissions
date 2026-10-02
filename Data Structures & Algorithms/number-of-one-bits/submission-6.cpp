class Solution {
public:
    int hammingWeight(uint32_t n) {
        //%2 cnt++
/*
2^ = x(x&(x-1) == 0)
        23 %2 cnt = 1
        11 %2 cnt = 2
        5 %2 cnt = 3
        2 %2 cnt = 3
        1 %2 cnt = 4
*/
        int cnt = 0;
        while(n)
        {
/*
            if(n&1) cnt++;
            n = n >> 1;
*/
            n &= (n-1);
            //n = 10111, n-1 = 10110
            //n = 10110, n-1 = 10101
            // n = 10100, n -1 = 10011
            // n = 10000, n -1 = 0'1111
            cnt++;
        }
        return cnt;
    }
};
