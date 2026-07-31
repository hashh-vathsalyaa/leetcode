class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        visited[node] = true;
        int n = isConnected.size();
        for(int neighbour=0; neighbour <n; neighbour++)
        {
            if(isConnected[node][neighbour] == 1 && !visited[neighbour])
            {
                dfs(neighbour, isConnected, visited);
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces=0;
        for(int i =0; i<n; i++)
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