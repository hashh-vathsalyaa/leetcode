class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        for(int i=0; i<n; i++)
        {
            pq.push({score[i],i});
        }
        vector<string> ans(n);
        int rank = 1;
        while(!pq.empty())
        {
            pair<int,int> curr = pq.top();
            pq.pop();

            int indx = curr.second;
            if(rank == 1)
            {
                ans[indx] = "Gold Medal";
            }
            else if(rank == 2)
            {
                ans[indx] = "Silver Medal";
            }
            else if(rank == 3)
            {
                ans[indx] = "Bronze Medal";
            }
            else{
                ans[indx] = to_string(rank);
            }
            rank++;
        }
        return ans;
    }
};