class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // what is difficult?
        // nums can be negative, and we do not know whether it can be positive or not until read
        
        // intuitive:
        // until hit 0/negative value, taking all nums will maximize the result, so take it
        // when finding 0, then need to check products after that
        // when finding negative, it would be fine if there are even number of negatives to include, if not, it needs to be treated same as 0 (skip and check product after that)
        //// =>
        
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for(int num:nums) {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }

        return res;
    }
};
