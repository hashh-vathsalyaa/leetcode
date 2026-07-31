class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        int area = 1;

        for(int i=0; i<4; i++)
        {
            int newRow = row+dr[i];
            int newCol = col+dc[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol] == 1)
            {
                area += dfs(newRow, newCol, grid, visited);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(!visited[row][col] && grid[row][col] == 1)
                {
                    int area = dfs(row, col, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};