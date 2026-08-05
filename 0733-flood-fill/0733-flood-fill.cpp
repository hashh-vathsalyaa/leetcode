class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int color)
    {
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i=0; i<4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && image[newRow][newCol] == oldColor)
            {
                dfs(newRow, newCol, image, oldColor, color);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == color)
        {
            return image;
        }
        
        dfs(sr,sc, image, oldColor, color);

        return image;
    }
};