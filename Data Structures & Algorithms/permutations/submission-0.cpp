class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> curr;
        dfs(nums, curr, pick);

        return res;
    }

    void dfs(vector<int>& nums, vector<int> curr, vector<bool>& pick) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        // backtracking

        for(int i=0; i<nums.size(); i++) {
            if(!pick[i]) {
                curr.push_back(nums[i]);
                pick[i] = true;
                dfs(nums, curr, pick);
                curr.pop_back();
                pick[i] = false;
            }
        }        
    }
};
