class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        vector<vector<int>> freq(nums.size() + 1);


        for(auto num : nums) {
            map[num]++;
        }

        for(auto c : map) {
            freq[c.second].push_back(c.first);
        }

        for(int i=freq.size()-1; i>0; --i) {
            for(int n : freq[i]) {
                res.push_back(n);
                if(res.size()==k) {
                    return res;
                }
            }
        }

        return res;
    }
};
