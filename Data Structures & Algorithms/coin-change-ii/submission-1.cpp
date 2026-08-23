class Solution {
public:
//    unordered_map<int, int> map;

    map<pair<int,int>, int> memo;
    int change(int amount, vector<int>& coins) {
        return dfs(0, 0, amount, coins);
    }
    
    int dfs(int index, int total, int amount, vector<int>& coins) {
        if(total == amount) {
            return 1;
        }

        if(total > amount || index == coins.size()) {
            return 0;
        }

        // if(map.count(total) > 0) {
        //     return map[total];
        // }

        auto key = make_pair(index, total);
        if (memo.count(key)) return memo[key];

        int take = dfs(index, total + coins[index], amount, coins);
        int skip = dfs(index + 1, total, amount, coins);

        return memo[key] = take + skip;

    }
};
