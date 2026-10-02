class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end())
        {
            s.insert(n);
            n = happy(n);
            if(n == 1) return true;
        }
        return false;
    }

    int happy(int n)
    {
        int result = 0;
        while(n)
        {
            int tmp = n%10;
            tmp *=tmp;
            result += tmp;
            n = n /10;
        }
        return result;
    }
};
