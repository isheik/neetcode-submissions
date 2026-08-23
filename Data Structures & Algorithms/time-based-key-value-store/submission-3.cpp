// This commented code does not work as unordered_map cannot use pair as the key without defining custom hash  function
// class TimeMap {

// public:
// unordered_map<pair<string, int>, string> m;
//     TimeMap() {
        
//     }
    
//     // can be o(1) if used unorderd_map
//     void set(string key, string value, int timestamp) {
// //        m[make_pair(key, timestamp)] = value;
//         m[{key, timestamp}] = value;

//     }
    
//     string get(string key, int timestamp) {
//         pair<string, int> k = {key, timestamp};
//         for(int i=timestamp; i>=0;i--) {
//             if(m.count(make_pair(key, i)) > 0) {
//                 return m[make_pair(key, i)];
//             }
//         }

//         return "";

//     }
// };


class TimeMap {

public:
//    unordered_map<string, unordered_map<int, string>> m;
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
        
    }
    
    // can be o(1) if used unorderd_map
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // for(int i=timestamp; i>=0; i--) {
        //     if(m[key].count(i)) {
        //         return m[key][i];
        //     }
        // }

        // return "";
        int left=0, right=m[key].size() - 1;
        string res = "";

        while(left <= right) {
            int mid = left+(right-left)/2;

            if(m[key][mid].first <= timestamp) {
                res = m[key][mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return res;
    }
};

// binary search => nlogn for sort, 