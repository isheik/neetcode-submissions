class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> path;

    bool exist(vector<vector<char>>& board, string word) {
        // iterate board
        // if the first char of words matches with the current board char,
        // do BFS from the cell
        // repeat the BFS if it can find next words char
        // when finding the word, return true
        ROWS = board.size();
        COLS = board[0].size();
        
        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if(i == word.size()) {
            return true;
        }

//        if(r<0 || c<0 || r >=ROWS || c >= COLS || board[r][c] != word[i] || board[r][c] == '#') {
        if(r<0 || c<0 || r >=ROWS || c >= COLS || board[r][c] != word[i] || path.count({r, c})) {

            return false;
        }

  //      board[r][c] = '#';
        path.insert({r, c});
        bool res = dfs(board, word, r+1, c, i+1) ||
        dfs(board, word, r, c+1, i+1) ||
        dfs(board, word, r-1, c, i+1) ||
        dfs(board, word, r, c-1, i+1);

//        board[r][c] = word[i];
        path.erase({r, c});
        return res;

    }
};
