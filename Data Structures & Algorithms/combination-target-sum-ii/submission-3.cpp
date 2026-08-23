// class Solution {
// public:
//     // unordered_set<vector<int>> set;
//     set<vector<int>> s;
//     vector<int> curr;
//     int currSum;
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         currSum = 0;
//         dfs(candidates, target, 0);
//         return vector<vector<int>>(s.begin(), s.end());
//     }

// private:
//     void dfs(vector<int>& candidates, int target, int idx) {
//         if(currSum == target) {
//             vector<int> tmp = curr;
//             cout << "here" << endl;
//             sort(tmp.begin(), tmp.end());
//             if(s.find(tmp) == s.end()) {
//                 s.insert(curr);
//             }
//             return;
//         } else if (currSum > target){
//             return;
//         }

//         curr.push_back(candidates[idx]);
//         currSum += candidates[idx];
//         dfs(candidates, target, idx+1);
//         curr.pop_back();
//         currSum -= candidates[idx];
//     }
// };

class Solution {
public:
    // unordered_set<vector<int>> set;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear(); // can be omitted, this makes sure res is empty when the same instance of the class (Solution) is called multiple times
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target, int i, vector<int>& cur, int total) {
        if(total == target) {
            res.push_back(cur);
            return;
        }
        if(total > target || i == candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target, i + 1, cur, total + candidates[i]);
        cur.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(candidates, target, i+1, cur, total);
    }

};
