// Time complexity O(nlogn)
// space O(1)
class Solution {
    private:
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](const auto& a, const auto& b){
            return a<b;
        };

        sort(nums.begin(), nums.end(), cmp);

        return nums[nums.size()-k];
    }

};
