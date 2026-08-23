// solved by bruteforce
// TC O(n x m (n+m)) SC T(n x m)

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<vector<int>> zeros;
//         int nrow = matrix.size();
//         int ncol = matrix[0].size();

//         for(int i=0; i<nrow; i++) {
//             for(int j=0; j<ncol; j++) {
//                 if(matrix[i][j] == 0) {
//                     zeros.push_back({i, j});
//                 }
//             }
//         }

//         for(auto zero : zeros) {
//             int row = zero[0];
//             int col = zero[1];
//             for(int i=0; i<nrow; i++) {
//                 matrix[i][col] = 0;
//             }

//             for(int j=0; j<ncol; j++) {
//                 matrix[row][j] = 0;
//             }
//         }
//     }
// };
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int nrow = matrix.size();
        int ncol = matrix[0].size();
        vector<bool> rbt(nrow);
        vector<bool> cbt(ncol);
        for(int i=0; i<nrow; i++) {
            for(int j=0; j<ncol; j++) {
                if(matrix[i][j] == 0) {
                    rbt[i] = true;
                    cbt[j] = true;
                }
            }
        }

        for(int i=0; i<nrow; i++) {
            if(rbt[i]) {
                for(int j=0; j<ncol; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0; i<ncol; i++) {
            if(cbt[i]) {
                for(int j=0; j<nrow; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
