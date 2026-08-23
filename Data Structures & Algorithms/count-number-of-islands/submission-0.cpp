class Solution {
public:
    int numis = 0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() <= 0) {
            return 0;
        }
        int rsize = grid.size();
        int csize = grid[0].size();

        for(int i=0; i<rsize; i++){
            for(int j=0; j<csize; j++){
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                }
            }
        }

        return numis++;
    }

    void bfs(vector<vector<char>>& grid, int orow, int ocol) {
        queue<pair<int, int>> queue;

        int rsize = grid.size();
        int csize = grid[0].size();

        queue.push({orow, ocol});

        while(!queue.empty()) {
            pair<int, int> c = queue.front();
            queue.pop();

            int row = c.first;
            int col = c.second;

            if(grid[row][col] != 'x' && grid[row][col] == '1') {
                grid[row][col] = 'x';
                
                if(row-1 >= 0 && grid[row-1][col])
                    queue.push({row-1, col});
                if(row+1 < rsize && grid[row+1][col])
                    queue.push({row+1, col});
                if(col-1 >= 0 && grid[row][col-1])
                    queue.push({row, col-1});
                if(col+1 < csize && grid[row][col+1])
                    queue.push({row, col+1});
            }
        }

        cout << orow << ocol << endl;

        numis++;
    }
};
