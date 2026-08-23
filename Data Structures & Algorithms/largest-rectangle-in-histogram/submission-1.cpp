// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> leftMost(n, -1);
//         vector<int> rightMost(n, n);
//         stack<int> stack;

//         for(int i=0; i<n; i++) {
//             while(!stack.empty() && heights[stack.top()] >= heights[i]) {
//                 stack.pop();
//             }
//             if(!stack.empty()) {
//                 leftMost[i] = stack.top();
//             }
//             stack.push(i);
//         }

//         while(!stack.empty()) stack.pop();

//         for(int i = n-1; i>=0; i--) {
//             while(!stack.empty() && heights[stack.top()] >= heights[i]) {
//                 stack.pop();
//             }
//             if(!stack.empty()) {
//                 rightMost[i] = stack.top();
//             }
//             stack.push(i);
//         }

//         int maxArea = 0;
//         for(int i = 0; i<n; i++) {
//             leftMost[i] += 1;
//             rightMost[i] -= 1;
//             maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
//         }

//         return maxArea;
//     }
// };


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;

        for(int i=0; i<heights.size(); i++) {
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]) {
                auto [index, height] = stack.top();
                maxArea = max(maxArea, height * (i-index));
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        while(!stack.empty()) {
            auto [index, height] = stack.top();
            maxArea = max(maxArea, height * (static_cast<int>(heights.size())-index));
            stack.pop();
        }
        return maxArea;
    }
};