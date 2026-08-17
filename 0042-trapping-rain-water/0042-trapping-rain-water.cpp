class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int totalWater = 0;
        for(int i=0; i<height.size() ; i++)
        {
            while(!st.empty() && height[i] > height[st.top()])
            {
                int bottom = st.top();
                st.pop();
                if(st.empty())
                {
                    break;
                }
                int left = st.top();
                int right = i;
                int Waterheight = min(height[left] , height[right]) - height[bottom];
                int width = right-left-1;
                totalWater += width*Waterheight;
            }
            st.push(i);
        }
        return totalWater;
    }
};