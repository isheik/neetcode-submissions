// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount+1, amount+1);
//         dp[0] = 0;

//         for(int i=1; i<=amount; i++) {
//             for(int j=0; j<coins.size(); j++) {
//                 if(coins[j] <=i) {
//                     dp[i] = min(dp[i], dp[i-coins[j]] + 1);
//                 }
//             }
//         }

//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };


class Solution {
public:
    unordered_map<int, int> memo;

    int dfs(int amount, vector<int>& coins) {
        if(amount == 0) return 0;

        if(memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int res = INT_MAX;

        for(int coin: coins) {
            if(amount - coin >= 0) {
                //res = min(res, 1+dfs(coins, amount-coin));
                int result = dfs(amount-coin, coins);
                if(result != INT_MAX) {
                    res = min(res, 1+result);
                }
            }
        }

        memo[amount] = res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);
        return (minCoins >= INT_MAX) ? -1 : minCoins;
    }
};