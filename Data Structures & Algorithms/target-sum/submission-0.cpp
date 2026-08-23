class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int a, vector<int>& nums, int target) {
        if(i == nums.size()) {
            if(target == a) {
                return 1;
            } else {
                return 0;
            }
        }

        return dfs(i+1, a+nums[i], nums, target) + dfs(i+1, a-nums[i], nums, target);
    }
};
