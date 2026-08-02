class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);

        return max(nums[0], max(helper(nums1), helper(nums2)));
    }

private:
    int helper(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for(int i=0; i<nums.size(); i++) {
            int newRob = max(rob1+nums[i], rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
        // max(n+rob(n+1...m), rob(n+1...m))
    }
};
