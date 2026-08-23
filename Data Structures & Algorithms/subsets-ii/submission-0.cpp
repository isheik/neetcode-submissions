class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // dfs?
        // determine whether we skip current or not
        // do dfs for skip one and non-skip one
        // when we reach last (base case), then sort the result set, push into a set which would be returned as the answer

        dfs(0, nums, {});

        return vector<vector<int>>(res.begin(), res.end());

    }
    void dfs(int i, vector<int>& nums, vector<int> cur) {
        if(i >= nums.size()) {
            sort(cur.begin(), cur.end());
            res.insert(cur);

            return;
        }

        dfs(i+1, nums, cur);

        cur.push_back(nums[i]);
        dfs(i+1, nums, cur);
    }
};
