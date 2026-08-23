class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> anagrams;

        for(string s : strs) {
            vector<int> chars(26, 0);
            string key = "";

            for(char c : s) {
                chars[c - 'a']++;
            }

            for(char c : chars) {
                key = key + "#" + c;
            }

            anagrams[key].push_back(s);
        }

        for(auto anagram : anagrams) {
                ans.push_back(anagram.second);
        }

        return ans;

    }
};
