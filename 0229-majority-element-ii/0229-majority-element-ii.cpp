class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 =0;
        int count2 =0;
        int n = nums.size();
        int f1=0, f2=0;
        int candidate1, candidate2;

        for(int i : nums)
        {
            if(i == candidate1)
            {
                count1++;
            }
            else if(i == candidate2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                candidate1 = i;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = i;
                count2 = 1;
            }
            
            else
            {
                count1--;
                count2--;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i] == candidate1)
            {
                f1++;
            }
            if(nums[i] == candidate2)
            {
                f2++;
            }
        }
        if(f1 > n/3 && f2 > n/3)
        {
            return {candidate1, candidate2};
        }
        else if(f1 > n/3)
        {
            return {candidate1};
        }
        else if(f2 > n/3)
        {
            return {candidate2};
        }
        else{
            return { };
        }
    }
};