class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int maxArea = 0;

        while(l<r) {
            if(heights[l] >= heights[r]) {
                maxArea = max(maxArea, heights[r] * (r-l));
                r--;
            } else {
                maxArea = max(maxArea, heights[l] * (r-l));
                l++;
            }
        }

        return maxArea;
    }
};
