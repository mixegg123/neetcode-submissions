class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> ans(m+n, 0);
/*
陣列 index:  0     1    ...   m+n-2   m+n-1
位數:       最高位               十位    個位
*/
        // "231" , "534", ans = "123354", last string is 低位...
        for(int i = m -1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                int tmp1 =( num1[i] - '0' )*(num2[j] - '0');
                tmp1 += ans[i+j+1];
                ans[i+j+1] = tmp1%10;
                ans[i+j] += (tmp1/10);
            }
        }

        string res = "";
        for(int i = 0; i<ans.size();i++)
            if(!(i==0&&ans[i] ==0))
                res += (ans[i]+'0');

        printf("res: %s\n", res.c_str());
        return res;
    }
};
