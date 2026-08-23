class Solution {
public:
    int maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    bfs(i, j, grid);
                }
            }
        }

        return maxArea;

    }

    void bfs(int row, int col, vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<vector<int>> queue;

        queue.push({row, col});
        int area = 0;

        while(!queue.empty()) {
            vector<int> cell = queue.front();
            queue.pop();

            if(grid[cell[0]][cell[1]] == -1) {
                continue;
            }

            grid[cell[0]][cell[1]] = -1;
            area++;
            
            for(auto direction : directions) {
                if(cell[0]+direction[0] >= 0 && cell[0]+direction[0] < grid.size() &&
                    cell[1]+direction[1] >= 0 && cell[1]+direction[1] < grid[0].size()) {
                        if(grid[cell[0]+direction[0]][cell[1]+direction[1]] == 1) {
                        queue.push({cell[0]+direction[0], cell[1]+direction[1]});
                        }

                    }

            }
        }

        maxArea = max(maxArea, area);
    }
};
