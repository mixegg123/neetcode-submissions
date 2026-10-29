class Solution {
public:
    bool isSubsequence(string s, string t) {
        //queue?
        queue<char> q;
        for(char c : s)
            q.push(c);

        for(char c : t)
        {
            if(q.front() == c)
                q.pop();
        }

        return q.empty();
    }
};