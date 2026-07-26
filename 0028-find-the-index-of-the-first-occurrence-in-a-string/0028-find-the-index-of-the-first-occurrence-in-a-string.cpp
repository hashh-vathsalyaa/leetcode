class Solution {
public:
    int strStr(string haystack, string needle) {
         int n = haystack.size();
    int m = needle.size();

    if (m == 0) return 0; // empty needle case

    for (int i = 0; i <= n - m; i++) {
        if (haystack.substr(i, m) == needle) {
            return i; // found at index i
        }
    }
    return -1;
    }
};