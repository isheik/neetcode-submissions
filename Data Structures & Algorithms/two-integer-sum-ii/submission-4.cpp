// got the best solution at the first time!
// learnt that we can do this by binary search too

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int l = 0;
        // int r = numbers.size()-1;

        // while(l < r) {
        //     int sum = numbers[l] + numbers[r];

        //     if(sum == target) {
        //         return {l+1, r+1};
        //     } else if(sum < target) {
        //         l++;
        //     } else {
        //         r--;
        //     }
        // }

        // return {};
        for(int i=0; i<numbers.size(); i++) {
           int l = i+1, r=numbers.size()-1;
           int tmp = target - numbers[i];

           while(l <= r) {
                int mid = l+(r-l)/2;
                if(numbers[mid] == tmp) {
                    return {i+1, mid+1};
                } else if (numbers[mid] < tmp) {
                    l=mid+1;
                } else {
                    r=mid-1;
                }
           }

        
        }
                    return {};
    }
};
