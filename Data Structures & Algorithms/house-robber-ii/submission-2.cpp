class Solution {
public:
    int rob(vector<int>& nums) {
        // if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() -1);       
        // return max(helper(vector<int>(nums.begin()+1, nums.end())),
        //             helper(vector<int>(nums.begin(), nums.end()-1)));
        return max(nums[0], max(helper(nums1), helper(nums2)));
    }

    int helper(vector<int> nums) {
        // if(nums.empty()) return 0;
        // if(nums.size() == 1) return nums[0];

        // vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // for(int i =2; i<nums.size(); i++) {
        //     dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        // }

        // return dp.back();
        int rob1 = 0, rob2 = 0;

        for(int num: nums) {
            int newRob = max(rob1+num, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }
};
