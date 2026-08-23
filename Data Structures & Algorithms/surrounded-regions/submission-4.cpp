class Solution {
public:
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void solve(vector<vector<char>>& board) {
        // do BFS starting from 0
        // when visits a cell of 0, mark as x and put adjacet 0 cells to queue to continue BFS
        // when queueing 0, ignore the cell if it is edges (edges are not considered as cell) 
        // ignore 0s on the edges

        // From edge rows, do dfs and mark cells as T
        // check each cell again, if a cell is T, then mark back to O
        // If a cell is O, then mark as X

        // dfs => (m x n) * (m+n) 

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(i == 0 || i ==board.size()-1 || j == 0 || j ==board[0].size()-1) {
                    dfs(i, j, board);
                }
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return;
        }
        
        if(board[row][col] == 'X' || board[row][col] == 'T') {
            return;
        }

        if(board[row][col] == 'O') {
            board[row][col] = 'T';
            
            for(auto [dy, dx] : dirs) {
                dfs(row+dy, col+dx, board);
            }
        }
    }
};
