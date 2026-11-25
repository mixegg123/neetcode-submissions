class Solution {
public:
    long long minEnd(int n, int x) {
/*提示(不給完整程式):

從低位往高位掃 x 的每一位
遇到 x 是 0 的位置,就把 n − 1 的最低位放進去,然後 n − 1 右移一位
*/
        long long ans = x;
        n = n -1; //ans is x, so we only need find the other n -1 element
        while(n--)
        {
            //0101
            //0111
            //1101
            //1111
            ans = (ans+1) | x;
        }
        return ans;
    }
};