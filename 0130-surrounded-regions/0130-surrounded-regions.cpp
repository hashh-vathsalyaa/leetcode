class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // First column and last column
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !visited[i][0])
            {
                q.push({i, 0});
                visited[i][0] = true;
            }

            if(board[i][m - 1] == 'O' && !visited[i][m - 1])
            {
                q.push({i, m - 1});
                visited[i][m - 1] = true;
            }
        }

        // First row and last row
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O' && !visited[0][j])
            {
                q.push({0, j});
                visited[0][j] = true;
            }

            if(board[n - 1][j] == 'O' && !visited[n - 1][j])
            {
                q.push({n - 1, j});
                visited[n - 1][j] = true;
            }
        }

        // BFS
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   board[nr][nc] == 'O' &&
                   !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        // Capture surrounded O's
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};