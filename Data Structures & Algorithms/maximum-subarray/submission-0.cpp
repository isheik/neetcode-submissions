// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size(), res = nums[0];
//         for (int i = 0; i < n; i++) {
//             int cur = 0;
//             for (int j = i; j < n; j++) {
//                 cur += nums[j];
//                 res = max(res, cur);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);

        for(int i=1; i<nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }

        return *max_element(dp.begin(), dp.end());

        
    }
};

