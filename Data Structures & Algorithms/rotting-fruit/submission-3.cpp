class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        // level bfs problem
        queue<pair<int,int>> q;
        
        int nrow = grid.size();
        int ncol = grid[0].size();

        for(int i=0; i<nrow; i++) {
            for(int j=0; j<ncol; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        int minutes = -1;

        while(!q.empty()) {
            // pick up from queue
            // add minutes
            // mark and put adjacent fruits
            int size = q.size();
            minutes++;

            for(int i = 0; i<size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for(const auto [dx, dy] : dirs) {
                    if(row + dx < 0 || row + dx >= nrow ||
                        col + dy < 0 || col + dy >= ncol) {
                            continue;
                        }
                    
                    if(grid[row + dx][col + dy] == 1) {
                        grid[row + dx][col + dy] = 2;
                        q.push({row + dx, col + dy});
                    }
                }
            }
        }

        bool remain = false;
        for(int i=0; i<nrow; i++) {
            for(int j=0; j<ncol; j++) {
                if(grid[i][j] == 1) {
                    remain = true;
                }
            }
        }

        return remain ? -1: minutes == -1 ? 0: minutes;
    }
};
