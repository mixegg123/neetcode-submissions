class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int temp = n;
        while(temp)
        {
            temp = happy(temp);
            if(temp == 1) return true;
            if(s.find(temp) != s.end())
                return false;
            s.insert(temp);
        }
        return true;
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
