// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int rob1 = 0, rob2 = 0;

//         for(int num: nums) {
//             int temp = max(num + rob1, rob2);
//             rob1 = rob2;
//             rob2 = temp;
//         }
//         return rob2;
//     }
// };


class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
//        memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }
        
        memo[i] = max(dfs(nums, i+1), nums[i] + dfs(nums, i+2));

        return memo[i];
    }
};
