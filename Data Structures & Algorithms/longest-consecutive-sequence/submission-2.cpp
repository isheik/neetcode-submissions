class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // //nums.sort(nums.begin(), nums.end(), greater<int>());
        // sort(nums.begin(), nums.end());

        // int len = 0;
        // int ans = 0;
        // int prev = numeric_limits<int>::min();
        // int counter = 0;
        // for(auto num: nums) {
        //     cout << num << endl;
        //     if(counter == 0) {
        //         len++;
        //         counter++;
        //         prev = num;
        //     } else if (prev + 1 == num){
        //         len++;
        //         prev = num;
        //         counter++;
        //     } else if (prev == num) {
        //         continue;
        //     } else {
        //         ans = max(ans, len);
        //         len = 0;
        //         counter = 0;
                
        //         len++;
        //         counter++;
        //         prev = num;
        //     }
        // }

        
        // ans = max(ans, len);
        // return ans;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {
            if(numSet.find(n-1) == numSet.end()) {
                int length = 1;
                while(numSet.find(n+length) != numSet.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
