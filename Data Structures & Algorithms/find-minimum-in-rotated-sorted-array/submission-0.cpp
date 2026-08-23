class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = numeric_limits<int>::max();

        for(int i=0; i<nums.size(); i++) {
            res = min(nums[i], res);
        }

        return res;
    }
};
