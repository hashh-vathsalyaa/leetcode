class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> temp;
        int n = nums.size();
        long long sum=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                int left = j+1;
                int right = n-1;
                while(left<right)
                {
                    sum = (long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        temp.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    
                        while(left<right && nums[left-1]==nums[left])
                        {
                            left++;
                        }
                        while(left<right && nums[right+1]==nums[right])
                        {
                            right--;
                        }
                    }

                    else if(sum > target)
                    {
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
            
        }

        return temp;
    }
};