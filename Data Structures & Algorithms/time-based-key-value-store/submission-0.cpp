class TimeMap {

public:
map<pair<string, int>, string> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[make_pair(key, timestamp)] = value;
    }
    
    string get(string key, int timestamp) {
        auto k = make_pair(key, timestamp);
        for(int i=timestamp; i>=0;i--) {
            if(m.count(make_pair(key, i)) > 0) {
                return m[make_pair(key, i)];
            }
        }

        return "";

    }
};
