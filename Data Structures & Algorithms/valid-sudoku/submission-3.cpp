class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> squares;

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board.size(); j++) {
                char cell = board[i][j];
                if(cell == '.') {
                    continue;
                }

                if(cols[j].count(cell) || rows[i].count(cell) || squares[(i/3)*3 + (j/3)].count(cell)) {
                    return false;
                }

                cols[j].insert(cell);
                rows[i].insert(cell);
                squares[(i/3)*3 + (j/3)].insert(cell);
            }
        }
        return true;
    }
};
