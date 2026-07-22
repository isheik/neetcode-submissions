
    // bool cmpa(const auto& a, const auto& b) {
    //     return a < b;
    // }

class Solution {
    private:
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            return a>b;
        });

        return nums[k-1];
    }

};
