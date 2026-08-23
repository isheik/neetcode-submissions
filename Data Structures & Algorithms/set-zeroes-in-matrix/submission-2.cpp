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


// T O(mxn) S O(m+n)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {

//         int nrow = matrix.size();
//         int ncol = matrix[0].size();
//         vector<bool> rbt(nrow);
//         vector<bool> cbt(ncol);
//         for(int i=0; i<nrow; i++) {
//             for(int j=0; j<ncol; j++) {
//                 if(matrix[i][j] == 0) {
//                     rbt[i] = true;
//                     cbt[j] = true;
//                 }
//             }
//         }

//         for(int i=0; i<nrow; i++) {
//             if(rbt[i]) {
//                 for(int j=0; j<ncol; j++) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         for(int i=0; i<ncol; i++) {
//             if(cbt[i]) {
//                 for(int j=0; j<nrow; j++) {
//                     matrix[j][i] = 0;
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        
        bool rowZero = false;

        for(int r=0; r<nrow; r++) {
            for(int c=0; c<ncol; c++) {
                if(matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if(r>0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for(int r=1; r<nrow; r++) {
            for(int c=1; c<ncol; c++) {
                if(matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int r=0; r<nrow; r++) {
                matrix[r][0] = 0;
            }
        }
        if(rowZero) {
            for(int c = 0; c<ncol; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};

