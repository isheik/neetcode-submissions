// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int l = 0;
//         int r = numbers.size()-1;

//         while(l < r) {
//             int sum = numbers[l] + numbers[r];

//             if(sum < target) {
//                 l++;
//             } else if(sum > target) {
//                 r--;
//             } else {
//                 return {l+1, r+1};
//             }
//         }

//         return {0, 0};
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i=0; i<numbers.size(); i++) {
            for(int j=i+1; j<numbers.size(); j++) {
                if(numbers[i]+numbers[j] == target) {
                    return {i+1, j+1};
                }
            }
        }
        return {};
    }
};


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         for (int i = 0; i < numbers.size(); i++) {
//             int l=i+1, r = numbers.size()-1;
//             int tmp = target - numbers[i];
//             while(l <= r) {
//                 int mid = l + (r - l) / 2;
//                 if (numbers[mid] == tmp) {
//                     return {i+1, mid+1};
//                 } else if(numbers[mid] < tmp) {
//                     l=mid+1;
//                 } else {
//                     r=mid-1;
//                 }
//             }
            
//         }
//         return {};
//     }
// };