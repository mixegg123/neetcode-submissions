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
            if(n&1) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};
