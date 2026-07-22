
    // bool cmpa(const auto& a, const auto& b) {
    //     return a < b;
    // }

class Solution {
    private:
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](const auto& a, const auto& b){
            return a>b;
        };

        sort(nums.begin(), nums.end(), cmp);

        return nums[k-1];
    }

};
