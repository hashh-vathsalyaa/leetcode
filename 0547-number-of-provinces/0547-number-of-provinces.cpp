class Solution {
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[i] = true;
        int n = isConnected.size();
        for(int it=0; it<n; it++)
        {
            if(isConnected[i][it] == 1 && !visited[it])
            {
                dfs(it, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
    return provinces;
    }
};