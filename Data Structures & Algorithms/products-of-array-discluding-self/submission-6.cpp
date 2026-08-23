// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> output;

//         for(int i=0; i<nums.size(); i++) {
//             int product = 1;
//             for(int j=0; j<nums.size(); j++) {
//                 if(i==j) continue;

//                 product = product * nums[j];
//             }
//             output.push_back(product);
//         }

//         return output;
//     }
// };
// brute force around10 min?
// O(n^2)



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;

        int product = 1;
        int zeros = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                            zeros++;
                continue;
            }
            product = product * nums[i];

        }

        for(int i=0; i<nums.size(); i++) {
            if(zeros >= 2) {
                output.push_back(0);
                continue;
            }

            if(zeros == 1 && nums[i] == 0) {
                output.push_back(product);
                continue;
            } else if (zeros == 1) {
                output.push_back(0);
                continue;
            }

            output.push_back(product/nums[i]);
        }
 
        

        return output;
    }
};


