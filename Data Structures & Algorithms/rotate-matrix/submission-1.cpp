// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         nrow = matrix.size();
//         ncol = matrix[0].size();

//         for(int i=0; i<nrow; i++) {
//             for(int j=0; j<ncol; j++) {
//                 int tmp = matrix[j][nrow-i];
//                 matrix[j][nrow-i] = matrix[i][j];
//                 matrix[i][j] = tmp;
//             }
//         }
//     }
// };


// could not solve
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=0;
        int r=matrix.size() - 1;

        while(l<r){
            for(int i=0; i<r-l; i++){
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l+i];

                matrix[top][l+i] = matrix[bottom-i][l];

                matrix[bottom-i][l] = matrix[bottom][r-i];

                matrix[bottom][r-i] = matrix[top+i][r];

                matrix[top+i][r] = topLeft;
            }

            r--;
            l++;
        }
    }
};

        // reverse(matrix.begin(), matrix.end());

//std::vector<int> src = {4, 5, 6};
//std::vector<int> dst = {1, 2, 3};
    //std::copy(src.begin(), src.end(), std::back_inserter(dst));
   // copy(src.begin(), src.end(), back_inserter(dst));