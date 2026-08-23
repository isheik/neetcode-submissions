// class Solution {
// public:
// //    unordered_map<int, int> map;

//     map<pair<int,int>, int> memo;
//     int change(int amount, vector<int>& coins) {
//         return dfs(0, 0, amount, coins);
//     }
    
//     int dfs(int index, int total, int amount, vector<int>& coins) {
//         if(total == amount) {
//             return 1;
//         }

//         if(total > amount || index == coins.size()) {
//             return 0;
//         }



//         auto key = make_pair(index, total);
//         if (memo.count(key)) return memo[key];

//         int take = dfs(index, total + coins[index], amount, coins);
//         int skip = dfs(index + 1, total, amount, coins);

//         return memo[key] = take + skip;

//     }
// };


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         sort(coins.begin(), coins.end());
//         int n = coins.size();
//         vector<vector<uint>> dp(n+1, vector<uint>(amount+1, 0));

//         for(int i=0; i<=n; i++) {
//             dp[i][0] = 1;
//         }

//         for(int i=n-1; i>=0; i--) {
//             for(int a=0; a<=amount; a++) {
//                 if(a >= coins[i]) {
//                     dp[i][a] = dp[i+1][a];
//                     dp[i][a] += dp[i][a-coins[i]];
//                 }
//             }
//         }

//         return dp[0][amount];
//     }    
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount+1, 0);
        dp[0] + 1;

        for(int i=coins.size()-1; i>=0; i--) {
            vector<uint> nextDP(amount+1, 0);
            nextDP[0] = 1;

            for(int a=1; a<=amount; a++) {
                nextDP[a] = dp[a];
                if(a-coins[i] >=0) {
                    nextDP[a] += nextDP[a-coins[i]];
                }
            }
            dp = nextDP;
        }

        return dp[amount];
    }
};