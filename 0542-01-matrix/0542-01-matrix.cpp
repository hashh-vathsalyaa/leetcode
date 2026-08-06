class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m));
        queue<pair<pair<int,int>, int>> q;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int steps = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                    if(mat[i][j] == 0)
                    {
                        visited[i][j] =1;
                        q.push({{i,j},0});
                    }
                    else
                    {
                        visited[i][j] = 0;
                    }
                
            }
        }

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            dist[r][c] = s;
            for(int i=0; i<4; i++)
            {
                int nrow = r+dr[i];
                int ncol = c+dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol] == 0)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, s+1});
                }
            }
        }

    return dist;
    }
};