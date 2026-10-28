class Solution {
public:
    string multiply(string num1, string num2) {
        //兩數相乘 數字數量最多 m+n
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();

        vector<int> ans(m+n, 0);
        //store in reverse order, start from m+n-1
        for(int i = m-1; i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                int temp = (num2[j] - '0') *(num1[i] - '0');
                int sum = temp + ans[i+j+1];
                ans[i+j+1] = (sum%10);
                ans[i+j] += (sum/10);
            }
        }

        string result = "";
        for(int i = 0;i<m+n;i++)
        {
            if(!(result.empty() && ans[i] == 0))
                result += (ans[i] + '0');
        }
        return result;
    }
};
