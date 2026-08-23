class Solution {
// BF
// 0. create hash map of t to count chars
// 1. iterate from the beginnng to end (start char)
// 2. in second loop, which has index to the end of substr,
// iterate from start index to the end. end will be increased one by one
// 3. when having the substr created by the steps 1 and 2,
// make hash of chars of substr
// 4. decrease the char count of t map and check whether the s substr map can consume all chars in t map
// 5. if it can, check the size of the substr and record min length
// 6. update min length if the new one is smaller than the previous ones
// 7. repeat 0 to 6


// Time (n^3)
// Space (T)

// Change tcount to array uppercase and lowercase English letters


// public:
//     string minWindow(string s, string t) {
//         int slen = s.size();
//         int tlen = t.size();
//         string shortest = "";

//         if(tlen > slen) {
//             return "";
//         }

//         for(int i=0; i<slen; i++) {
//             for(int j=i; j<=slen; j++) {
//                 if(tlen > j-i+1) {
//                     continue;
//                 }

//                 unordered_map<char, int> tcount;
//                 for(int l=0; l<tlen; l++) {
//                     tcount[t[l]]++;
//                 }

//                 string str = s.substr(i, j-i+1);

//                 for(int k=0; k<str.size(); k++) {
//                     if(tcount.find(str[k]) != tcount.end()) {
//                         tcount[str[k]]--;
//                     }
//                 }

//                 bool alldone = true;
//                 for(auto [key, val] : tcount) {
//                     if(val > 0) {
//                         alldone = false;
//                         break;
//                     }
//                 }

//                 if(alldone && (shortest == "" || (shortest.size() > str.size()))) {
//                     shortest = str;
//                 }
//             }
//         }

//         return shortest;
//     }

public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        int have = 0;


        // check whether the substr contains all t chars
        // if so, then update return by substr

        unordered_map<char, int> window;
        unordered_map<char, int> tcount;
        //pair<int, int> res = {-1, -1};
        int lres = -1;
        int resLen = INT_MAX;
        int l=0;

        for(char c : t) {
            tcount[c]++;
        }
        int need = tcount.size();

        for(int r=0; r<s.size(); r++) {
            char c = s[r];
            window[c]++;

            if(tcount.count(c) && window[c] == tcount[c]) {
                have++;
            }

            while(have == need) {
                if((r-l+1) < resLen) {
                    resLen = r-l+1;
                    lres = l;
                }

                window[s[l]]--;
                if(tcount.count(s[l]) && window[s[l]] < tcount[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(lres, resLen);
    }
};
