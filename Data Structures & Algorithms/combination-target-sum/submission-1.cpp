class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // take or not take decision tree including self
        // exit condtion = sum is more than target
        
        // consider the choices as decision tree
        // then, do dfs for the tree
        // record current choices 
        // when reach to the end condition, sum is same as the current choices,
        // add to the result
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(0, nums, target, cur, 0);

        return vector<vector<int>>(res.begin(), res.end());
        
    }

    void dfs(int i, vector<int>& nums, int target, vector<int>& cur, int sum) {
        if (i >= nums.size()) return;
        if(sum > target) {
            return;
        }
        if(sum == target) {
            res.insert(cur);
        }

        // pick case
        cur.push_back(nums[i]);
        sum += nums[i];
        dfs(i, nums, target, cur, sum);

        // non-pick case
        cur.pop_back();
        sum -= nums[i];
        dfs(i+1, nums, target, cur, sum);
    }
};
