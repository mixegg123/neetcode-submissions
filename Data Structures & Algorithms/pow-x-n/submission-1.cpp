class Solution {
public:
    double myPow(double x, int n) {
        //negative or not
        //a base, and double the base in every shift
        //final check by n is negative or not
        //x^n -> n can split to 2 order (like 13 can spli to x^8 * x^4 * x^2 * x^1 ----> x^13)
        double base = x, ans = 1;
        bool negative = n < 0;
        if(negative)
            n = n * -1;
        
        while(n)
        {
            //5 -> 0101
            if(n&1)
                ans *= base;
            base *= base;
            n = n >>1;
        }
        return (negative) ? 1.0/ans: ans ;
    }
};
