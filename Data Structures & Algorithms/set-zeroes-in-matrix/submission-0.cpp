class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        int nrow = matrix.size();
        int ncol = matrix[0].size();

        for(int i=0; i<nrow; i++) {
            for(int j=0; j<ncol; j++) {
                if(matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        for(auto zero : zeros) {
            int row = zero[0];
            int col = zero[1];
            for(int i=0; i<nrow; i++) {
                matrix[i][col] = 0;
            }

            for(int j=0; j<ncol; j++) {
                matrix[row][j] = 0;
            }
        }
    }
};
