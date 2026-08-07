class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> topo;
        for(int i=0; i<numCourses; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for(int i=0; i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            topo.push_back(n);
            for(auto it : adj[n])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if(topo.size() == numCourses)
        {
            return topo;
        }

        return {};
    }
};