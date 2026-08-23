class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        set<vector<int>> res;
        
        sort(nums.begin(), nums.end());

        for(int i=0; i<len; i++) {
            for(int j=i+1; j<len; j++) {
                for(int k=j+1; k<len; k++) {
                    if(nums[i]+nums[j]+nums[k]==0) {
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
