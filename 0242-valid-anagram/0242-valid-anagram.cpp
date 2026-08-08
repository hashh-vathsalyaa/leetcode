class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> str;
        unordered_map<char,int> text;
        bool flag = false;
        for(char ch : s)
        {
            str[ch]++;
        }

        for(char ch : t)
        {
            text[ch]++;
        }

        return str == text;
    }
};