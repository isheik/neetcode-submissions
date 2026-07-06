class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a max heap <number, that's appearance>
        // get top element k times

//        priority_queue<pair<int,int>, vector<pair<int, int>>, less<int>> heap;
        priority_queue<pair<int,int>> heap;

        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }

        // int i=0;       while(i<nums.size()) {
        //     int c = 0;
            
        //     for(int j=0; j<nums.size(); j++) {
        //         if(nums[i] == nums[j]) {
        //             c++;
        //         }

        //         heap.insert({i, c});

        //         i++;
        //     }
        // }

        for(const auto& entry : m) {
            heap.push({entry.second, entry.first});
        }

        vector<int> result;

        for(int j=0; j<k; j++) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        

        return result;
    }
};
