class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(int num : nums) {
            if(numSet.find(num-1) == numSet.end()) {
                int streak = 1;
                int cur = num+1;
                
                while(numSet.find(cur) != numSet.end()) {
                    streak++;
                    cur = cur+1;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
