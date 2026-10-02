class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string str: strs)
        {
            result += str;
            result += '~';
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string tmp = "";
        for(char c : s)
        {
            if(c != '~')
            {
                tmp += c;
            } 
            else
            {
                result.push_back(tmp);
                tmp = "";
            }
        }
        return result;
    }
};
