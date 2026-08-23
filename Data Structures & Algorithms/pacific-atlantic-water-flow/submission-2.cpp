// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         // Do BFS starting from all cell
//         // for each iteration
//         // - check four directions heights
//         //  - if height is higher than the cell, then do not put to the queue
//         //  - if height is lower than the cell:
//         //    - put to the queue
//         //  - if it reaches to out of the boudary, then check whether it goes to Pacific/Atlantic
//         //  - if the current start cell both reach to P and A, then add to the answer list

//         // doble for loop. inside it, do BFS
//         // in the loop, manage flags that hold status whether arrived P/A oceans
//         // if both flags are on, add the starting cell to list and continue

//         int n = heights.size();
//         int m = heights[0].size();

//         vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
//         set<pair<int, int>> res;
//         vector<vector<bool>> memo(n, vector<bool>(m, false));

//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 bool pacific = false;
//                 bool atlantic = false;

//                 queue<pair<int, int>> q;

//                 q.push(make_pair(i, j));

//                 while(!q.empty()) {
//                     auto [y, x] = q.front();
//                     q.pop();

//                     if(memo[i][j]){
//                         res.insert({i, j});
//                         break;

//                     }

//                     for(auto [dy, dx] : dirs) {
//                         if(x+dx < 0 || y+dy < 0) {
//                             pacific = true;
//                         }
//                         if(x+dx >= m || y+dy >= n) {
//                             atlantic = true;
//                         }
//                     }

//                     if(pacific && atlantic) {
//                         res.insert({i, j});
//                         memo[i][j] = true;
//                         break;                       
//                     }

//                     for(auto [dy, dx] : dirs) {
//                         // check all for directions
//                         // compare the current cell height with 4 directions
//                         // if neibouring cell is less than the current cel height, add to queue

//                         if(x+dx >= 0 && x+dx < m && y+dy >= 0 && y+dy < n) {
//                             if(heights[y][x] >= heights[y+dy][x+dx]) {
//                                 q.push({y+dy, x+dx});
//                             }
//                         }  
//                     }
                    
//                 }
//             }
//         }

//         return vector<vector<int>>(res.begin(), res.end());

//     }
// };


// class Solution {
// public:
//     int ROWS, COLS;
//     bool pacific, atlantic;
//     vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         ROWS = heights.size();
//         COLS = heights[0].size();
//         vector<vector<int>> res;

//         for (int r = 0; r < ROWS; r++) {
//             for (int c = 0; c < COLS; c++) {
//                 pacific = false;
//                 atlantic = false;
//                 dfs(heights, r, c, INT_MAX);
//                 if (pacific && atlantic) {
//                     res.push_back({r, c});
//                 }
//             }
//         }

//         return res;
//     }

//     void dfs(vector<vector<int>>& heights, int r, int c, int prevVal) {
//         if (r < 0 || c < 0) {
//             pacific = true;
//             return;
//         }
//         if (r >= ROWS || c >= COLS) {
//             atlantic = true;
//             return;
//         }
//         if (heights[r][c] > prevVal) {
//             return;
//         }

//         int tmp = heights[r][c];
//         heights[r][c] = INT_MAX;
//         for (auto& dir : directions) {
//             dfs(heights, r + dir[0], c + dir[1], tmp);
//             if (pacific && atlantic) {
//                 break;
//             }
//         }
//         heights[r][c] = tmp;
//     }
// };


class Solution {
    vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS=heights.size(), COLS=heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for(int c=0; c<COLS; ++c) {
            dfs(0, c, pac, heights);
            dfs(ROWS-1, c, atl, heights);
        }

        for(int r=0; r<ROWS; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS-1, atl, heights);
        }

        vector<vector<int>> res;

        for(int r=0; r<ROWS; ++r) {
            for(int c=0; c<COLS; ++c) {
                if(pac[r][c] && atl[r][c])
                    res.push_back({r, c});
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for(auto [dr, dc] : directions) {
            int nr = r+dr, nc = c+dc;

            if(nr>=0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }

};