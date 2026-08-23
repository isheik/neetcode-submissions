// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return dfs(0, 0, nums, target);
//     }

//     int dfs(int i, int a, vector<int>& nums, int target) {
//         if(i == nums.size()) {
//             if(target == a) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }

//         return dfs(i+1, a+nums[i], nums, target) + dfs(i+1, a-nums[i], nums, target);
//     }
// };


class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> m;
        return dfs(0, 0, nums, target, m);
    }

    int dfs(int i, int a, vector<int>& nums, int target, map<pair<int, int>, int>& m) {
        if(i == nums.size()) {
            if(target == a) {
                return 1;
            } else {
                return 0;
            }
        }

        auto key = make_pair(i, a);
        if(m.count(key) > 0) {
            return m[key];
        }

        int res = 0;
        int positive = dfs(i+1, a+nums[i], nums, target, m);
        int negative = dfs(i+1, a-nums[i], nums, target, m);

        m[key] = positive + negative;

        return m[key];
    }
};
