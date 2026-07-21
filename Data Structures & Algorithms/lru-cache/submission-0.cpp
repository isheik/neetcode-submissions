class LRUCache {
// hashmap
// how to decide LEAST RECENTLY used key?
// - store timestamp
// - just called count is not correct
// key -> key
// value -> value
// in map, store one more? like last used time stamp?
// but if so, need to check all keys in map, possibly take O(n)
// use both map and queue?
// so, map<key, value> also at the same time, record the key to queue?
// when exceeding capacity, check the top of queue and pop
// if same key comes,

// the issue is, how to handle queue when same key comes?
private:
    vector<pair<int, int>> cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(int i=0; i<cache.size(); i++) {
            if(cache[i].first == key) {
                pair<int, int> tmp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0; i<cache.size(); i++) {
            if(cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == capacity) {
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
    }
};
