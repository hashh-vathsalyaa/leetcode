class Solution {
public:
    bool detect(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path)
    {
        visited[node] = true;
        path[node] = true;

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(detect(it, adj, visited, path) == true)
                {
                    return true;
                }
            }
            else if(path[it])
            {
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites)
        {
            int a = e[0];
            int b = e[1];

            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(detect(i, adj, visited, path) == true)
                {
                    return false;
                }
            }
        }
        return true;
    }
};