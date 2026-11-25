class Solution {
public:
    string simplifyPath(string path) {
        vector<string> words;
        string ans = "";
        int l = 0;

        while(l<path.size())
        {
            while(l<path.size() &&path[l] == '/')
                l++;
            
            if(l == path.size())
                break;
            int pos = path.find("/", l);
            
            //not found, its end of word
            if(pos == -1)
                pos = path.size();
            
            string s = path.substr(l,pos-l);
            if(s == "..")
            {
                if(!words.empty())
                    words.pop_back();
            } else if (s != "."){
                words.push_back(s);
            }
            //update l to pos position
            l = pos;
        }

        for( auto &word :words)
            ans += "/" + word; 

        return ans.empty()?"/":ans;
    }
};