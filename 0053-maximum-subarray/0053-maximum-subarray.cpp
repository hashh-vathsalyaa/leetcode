class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cSum = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            cSum = max(nums[i], nums[i]+cSum);
            maxSum = max(maxSum, cSum);
        }
        return maxSum;
    }
};