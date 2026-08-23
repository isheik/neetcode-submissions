class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l<=r) {
            int mid = (l+r) / 2;

            if(target==nums[mid]) {
                return mid;
            }

            if(nums[l] <= nums[mid]) {
                if(target > nums[mid] || target < nums[l]) {
                    l=mid+1;      
                } else {
                    r=mid-1;
                }
            } else {
                if(target < nums[mid] || target > nums[r]) {
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};
// mid vs target -> if target < mid and nums[left] > target => l=mid+1
// -> if target == mid true
// -> if target > mid  && right 


// 1 target < mid && rotated already(nums[l] > target)
//=> r=mid+1
// 2 target < mid && not past left(nums[l] < target)
//=> r=mid-1
// 3 target > mid && rotated and past mid(nums[r] < target)
//=> l=mid-1
// 4 target > mid && rotated and not passed mid yet (nums[r] > target)
//=> l=mid+1


