class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int time = -1;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                else if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        if(fresh==0)
        {
            return 0;
        }

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto[r,c] = q.front();
                q.pop();
                int dr[] = {-1,1,0,0};
                int dc[] = {0,0,-1,1};
                for(int i=0; i<4; i++)
                {
                    int newRow = r+ dr[i];
                    int newCol = c+ dc[i];

                    if(newRow<row && newCol<col && newRow>=0 && newCol>=0 && grid[newRow][newCol] == 1)
                    {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        fresh--;
                    }
                }
            }
            time++;
        }

        if(fresh>0)
        {
            return -1;
        }
        else
        {
            return time;
        }
    }
};