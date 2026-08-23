// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         // vector<int> ans;

//         // // for(int i=0; i<nums.size(); i++) {
//         //     int product = 1;
//         //     for(int j=0; j<nums.size(); j++) {
//         //         // if(i != j) {
//         //             product = product * nums[j];
//         //         // }
//         //     }
//         //     // ans.push_back(product);
            
//         // // }

//         // for(int i=0; i<nums.size(); i++) {
//         //     int num;
            
//         //     if(nums[i] != 0) {
//         //         num = product / nums[i];
//         //     } else {
//         //         num = 0;
//         //     }
            
//         //     ans.push_back(num);
//         // }
//         // return ans;

//         int n = nums.size();
//         vector<int> result(n, 1);

//         int prefix = 1;

//         for(int i = 0; i<n; i++) {
//             result[i] = prefix;
//             prefix = prefix * nums[i];
//         }

//         int postfix = 1;
//         for(int i=n-1; i>=0; i--) {
//             result[i] = result[i] * postfix;
//             postfix = postfix * nums[i];
//         }

//         return result;


        
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;

        vector<int> result(nums.size(), 0);

        for(int i=0; i<nums.size(); i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;

        for(int i=nums.size()-1; i>=0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }

        return result;
    }
};

