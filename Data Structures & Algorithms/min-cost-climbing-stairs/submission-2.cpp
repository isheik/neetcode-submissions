// solved, but could not debug well wheere
// min(dp[i-1], dp[i-2]) was wrongly written as min(cost[i-1], cost[i-2])

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size(), 0);

//         dp[0]=cost[0];
//         dp[1]=cost[1];

//         for(int i=2; i<cost.size(); i++) {
//             dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
//         }

//         return min(dp[cost.size()-1], dp[cost.size()-2]);
//     }
// };

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(dfs(cost, 0), dfs(cost, 1));
//     }

//     int dfs(vector<int>& cost, int i) {
//         if(i >= cost.size()) {
//             return 0;
//         }

//         return cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
//     }
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2; i<cost.size(); i++) {
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }

        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
};