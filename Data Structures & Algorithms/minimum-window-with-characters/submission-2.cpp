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

public:
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        string shortest = "";

        if(tlen > slen) {
            return "";
        }

        for(int i=0; i<slen; i++) {
            for(int j=i; j<=slen; j++) {
//            for(int j=1; i+j<=slen; j++) {
              //  cout << s.substr(i,j) << endl;
                // cout << i << endl;
                // cout << j << endl;

                if(tlen > j-i+1) {
       //         if(tlen > j) {
                    continue;
                }
//                cout << "hello" << endl;

                unordered_map<char, int> tcount;
                for(int l=0; l<tlen; l++) {
                    tcount[t[l]]++;
                }

//                string str = s.substr(i, j);
                string str = s.substr(i, j-i+1);

                //unordered_map<char, int> strcount;

                //need to check whether the substr can consume all t chars
                // how can i check whether t map is consumed all or not?
                for(int k=0; k<str.size(); k++) {
                 //   if(tcount.count(str[k]) > 0) {
                    if(tcount.find(str[k]) != tcount.end()) {
                        tcount[str[k]]--;
                    }
                }

                bool alldone = true;
                for(auto [key, val] : tcount) {
                    if(val > 0) {
                        alldone = false;
                        break;
                    }
                }

//                if(shortest == "" || shortest.size() > str.size()) {

                if(alldone && (shortest == "" || (shortest.size() > str.size()))) {
                    shortest = str;
                }

//                shortest = min(shortest, str.size());
            }
        }

        return shortest;
    }
};
