class Solution {
public:

    string encode(vector<string>& strs) {
#if 1
        //use number# as prefix to distinguish a word
        string result = "";
        for(const string &str: strs)
        {
            result += to_string(str.size());
            result += '#';
            result += str;
        }
        return result;
#else
        string result;
        for(string str: strs)
        {
            result += str;
            result += '~';
        }
        return result;
#endif

    }

    vector<string> decode(string s) {
#if 1
        //substr (pos, length)
        int i = 0, j = 0;
        vector<string> result;
        while(i<s.size())
        {
            j = i;
            while(s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + len;
            result.push_back(s.substr(i, len));
            i = j; 
        }
        return result;
#else
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
#endif
    }
};
