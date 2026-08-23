class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(auto [dy, dx] : dirs) {
                int r = row+dy;
                int c = col+dx;

                if(r<0 || r>=m || c < 0 || c>=n ||
                    grid[r][c] != INT_MAX) {
                    continue;
                }

                 grid[r][c] = grid[row][col] + 1;
                 q.push({r, c});
            }
        }
    }
};
