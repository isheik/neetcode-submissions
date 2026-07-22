class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](const int& a, const int& b) {
            return a<b;
        };
//        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

        priority_queue<int, vector<int>> heap;

        for(int i=0; i<nums.size(); i++) {
            heap.push(nums[i]);
        }

        for(int i=0; i<k-1; i++) {
            heap.pop();
        }

        return heap.top();
        
    }
};