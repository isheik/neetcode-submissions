class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int res = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     unordered_set<char> charSet;
        //     for (int j=i; j < s.size(); j++){
        //         if(charSet.find(s[j]) != charSet.end()) {
        //             break;
        //         }
        //         charSet.insert(s[j]);
        //     }

        //     res = max(res, (int)charSet.size());
        // }
        // return res;

        int l = 0;
        int res = 0;
        unordered_set<char> set;

        for(int r=0; r<s.size(); r++) {
            while (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res,(int)set.size());
        }

        return res;
    }
};