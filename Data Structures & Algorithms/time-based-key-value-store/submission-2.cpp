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
    unordered_map<string, unordered_map<int, string>> m;
    TimeMap() {
        
    }
    
    // can be o(1) if used unorderd_map
    void set(string key, string value, int timestamp) {
//        m[make_pair(key, timestamp)] = value;
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        //pair<string, int> k = {key, timestamp};
        // for(int i=timestamp; i>=0;i--) {
        //     if(m.count(make_pair(key, i)) > 0) {
        //         return m[make_pair(key, i)];
        //     }
        // }
        for(int i=timestamp; i>=0; i--) {
            if(m[key].count(i)) {
                return m[key][i];
            }
        }

        return "";

    }
};
