// O(n^2), O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++) {
//             for(int j=i+1; j<nums.size(); j++) {
//                 if(nums[i] == nums[j]) {
//                     return nums[i];
//                 }
//             }
//         }

//         return 0;
//     }
// };


// TC O(n) , SC O(n)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> set;

//         for(int i=0; i<nums.size(); i++) {
//             if(set.find(nums[i]) != set.end()) {
//                 return nums[i];
//             } else {
//                 set.insert(nums[i]);
//             }
//         }

//         return 0;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int prev = -1;

        for(int i=0; i<nums.size(); i++) {
            if(prev == nums[i]) {
                return prev;
            } else {
                prev = nums[i];
            }
        }

        return 0;
    }
};