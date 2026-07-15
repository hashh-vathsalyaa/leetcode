class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> temp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int ele=0; ele < n-1; ele++)
        {
            if(ele>0 && nums[ele] == nums[ele-1])
            {
                continue;
            }
            int i = ele+1;
            int j = n-1;
            while(i<j)
            {
                int sum = nums[i]+nums[j]+nums[ele];
                if(sum == 0)
                {
                    temp.push_back({nums[ele], nums[i], nums[j]});
                    i++;
                    j--;
                    
                    while(i<j && nums[i] == nums[i-1])
                    {
                        i++;
                    }
                    while(i<j && nums[j] == nums[j+1])
                    {
                        j--;
                    }
                }
                else if(sum > 0)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return temp;
    }  
};