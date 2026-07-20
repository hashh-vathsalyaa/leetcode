class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeen;
        int left = 0;
        int best =0;
        for(int r =0; r<(int)s.size(); r++)
        {
            if(lastSeen.count(s[r]))
            {
                left = max(left, lastSeen[s[r]]+1);
            }
            lastSeen[s[r]] = r;
            best = max(best, r-left+1);
        }
        return best;
    }
};