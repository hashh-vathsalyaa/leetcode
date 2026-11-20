class Solution {
public:
    int reversePairs(int low, int mid, int high, vector<int>& nums)
    {
        int count = 0;
        int right = mid+1;
        for(int i=low; i<=mid; i++)
        {
            while(right <= high && (long long)nums[i] > 2LL * nums[right])
            {
                right++;
            }
            count += (right -(mid+1));
        }
        return count;
    }
    void merge(int low, int mid, int high, vector<int>& nums)
    {
        int left = low;
        int right= mid+1;
        vector<int> temp;
        while(left<=mid && right<=high)
        {
            if(nums[left] < nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low; i<=high; i++)
        {
            nums[i] = temp[i-low];
        }
    }
    int mergeSort(int left, int right, vector<int>& nums)
    {
        int count = 0;
        if(left >= right)
        {
            return 0;
        }
        int mid = (left+right)/2;
        count += mergeSort(left, mid, nums);
        count += mergeSort(mid+1, right, nums);
        count += reversePairs(left, mid, right, nums);
        merge(left, mid, right, nums);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1, nums);
    }
};