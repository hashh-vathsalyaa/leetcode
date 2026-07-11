class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> temp(n);
        int m =nums.size() - k;
        int j=0;
        for(int i=m; i<n; i++)
        {
            temp[j] = nums[i];
            j++;
        }
        for(int i=0; i<m; i++)
        {
            temp[j] = nums[i];
            j++;
        }
        nums = temp;
    }
};