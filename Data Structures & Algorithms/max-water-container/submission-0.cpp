class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int res = 0;
        // for (int i=0; i<heights.size(); i++) {
        //     for(int j=i; j<heights.size(); j++) {
        //         res = max(res, min(heights[i], heights[j]) * (j-i));
        //     }
        // }

        // return res;

        int left = 0;
        int right = heights.size()-1;
        int res = numeric_limits<int>::min();

        while(left < right) {
            res = max(res, min(heights[left], heights[right]) * (right-left));

            if(heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;

    }

};
