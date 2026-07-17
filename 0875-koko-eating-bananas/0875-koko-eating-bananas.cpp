class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high= *max_element(piles.begin(), piles.end());
        while(low<=high)
        {
            int mid = (low+high)/2;
            long long sum =0;
            for(int pile : piles)
            {
                sum +=(pile +mid-1)/mid;
            }

            if(sum <= h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};