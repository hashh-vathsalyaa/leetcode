class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row+dr[i];
            int newCol = col+dc[i];

            if(newRow >=0 && newCol<m && newRow<n && newCol>=0 && !visited[newRow][newCol] && grid[newRow][newCol] == '1')
            {
                dfs(newRow, newCol, grid, visited);
            }
        }    
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(!visited[row][col] && grid[row][col] == '1')
                {
                    count++;
                    dfs(row, col, grid, visited);
                }
            }
        }
        return count;
    }
};