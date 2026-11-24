class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> mpp;
        mpp[0] = 1;
        long long sum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            long long rem = sum-k;
            count += mpp[rem];
            mpp[sum]++;
        }
        return count;
    }
};