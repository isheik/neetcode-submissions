// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++) {
//             bool found = false;
//             for(int j = 0; j < nums.size(); j++) {
//                 if(i != j && nums[i] == nums[j]) {
//                     cout << nums[i] << endl;
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found) {
//                 cout << "hello" << endl;
//                 return nums[i];
//             }
//         }

//         return 0;
//     }
// };


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num: nums) {
            if(seen.count(num)) {
                seen.erase(num);
            } else {
                seen.insert(num);
            }
        }

        return *seen.begin();
    }

};