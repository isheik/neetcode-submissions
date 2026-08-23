// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> output;
//         for(int i=0; i<=n; i++) {
//             int c = 0;
//             int num = i;

//             while(num > 0) {
//                 if(num % 2 == 1) {
//                     c++;
//                 }
//                 num = num/2;
//             }
//             output.push_back(c);
//         }

//         return output;
//     }
// };


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        int offset = 1;

        for(int i = 1; i<=n; i++) {
            if(offset * 2 == i) {
                offset = i;
            }
            dp[i] = 1+dp[i-offset];
        }

        return dp;
        
    }
};
