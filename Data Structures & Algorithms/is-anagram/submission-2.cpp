class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        // sort solution T O(nlogn) S O(1)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for(int i=0; i<=s.size(); i++) {
        //     if(s[i] != t[i]) {
        //         return false;
        //     }
        // }
        // return true;

        // map solution T O(n) S O(n)
        // unordered_map<char, int> map;
        // unordered_map<char, int> map2;

        // for(int i=0; i<=s.size(); i++) {
        //     map[s[i]]++;
        // }

        // for(int i=0; i<=t.size(); i++) {
        //     map2[t[i]]++;
        // }

        // for(auto e : map) {
        //     if(e.second != map2[e.first]) {
        //         return false;
        //     }
        // }

        // return true;

        // array solution
        vector<int> chars(26, 0);
        vector<int> chars2(26, 0);

        for(int i=0; i<s.size(); i++) {
            chars[s[i] - 'a']++;
            chars2[t[i] - 'a']++;            
        }

        for(int i=0; i<25; i++) {
            if(chars[i] != chars2[i]) {
                return false;
            }
        }
        return true;
    }
};
