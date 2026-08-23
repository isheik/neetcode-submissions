// Solved by myself in about 50 minutes
// Overlooked edge case where the first binary search boundary (forgot to put = to > and <)
// Also, second search r was initialized m-1 where it should be n-1

// Brute force Time O(n^2) Space O(1)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(matrix[i][j] == target) return true;
//             }
//         }

//         return false;
//     }
// };

// Double Binary search
// log(m) + log(n) = log(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // get mid
        // check whether the target is in the mid array
        // if target is either less than the lowest in the array/larger than the highest in the array
        // then, shift left/right index depending on the result
        // (if lower, then right=mid-1, if larger, then left is mid+1)

        int m = matrix.size();
        int n = matrix[0].size();

     
        int l = 0;
        int r = m-1;

        int targetIndex = 0;

        while(l<=r) {
            int mid = l+(r-l / 2);

            vector<int> curr = matrix[mid];

            if(target < curr[0]) {
                r = mid-1;
            } else if (target > curr[n-1]) {
                l = mid+1;
            } else if (target >= curr[0] && target <= curr[n-1]) {
                targetIndex = mid;
                break;
            }
        }

        //l = 0;
        r = n-1;

        vector<int> mat = matrix[targetIndex];

        while(l<=r) {
            int mid = l+(r-l / 2);

            if(target < mat[mid]) {
                r = mid-1;
            } else if (target > mat[mid]) {
                l = mid+1;
            } else {
                return true;
            }
        }

        return false;
    }
};