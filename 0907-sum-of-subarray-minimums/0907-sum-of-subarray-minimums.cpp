class Solution {
public:
    vector<int> PSE(vector<int>& arr)
    {
        stack<int> st;
        vector<int> pse(arr.size());
        for(int i=0; i<arr.size(); i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    vector<int> NSE(vector<int>& arr)
    {
        stack<int> st;
        vector<int> nse(arr.size());

        for(int i=arr.size()-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nse[i] = arr.size();
            }
            else
            {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long total= 0;
        int mod = (int)1e9+7;
        vector<int> nse = NSE(arr);
        vector<int> pse= PSE(arr);
        for(int i=0; i<arr.size(); i++)
        {
            long long start = i-pse[i];
            long long end = nse[i]-i;

            total = (total + start * end * 1LL * arr[i]) % mod; 
        }

        return total;
    }
};