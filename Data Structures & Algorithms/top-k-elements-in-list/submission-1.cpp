class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int, int> count;
        // for(int num : nums) {
        //     count[num]++;
        // }

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // for (auto& entry : count) {
        //     heap.push({entry.second, entry.first});
        //     if(heap.size() > k) {
        //         heap.pop();
        //     }
        // }

        // vector<int> res;
        // for(int i = 0; i < k; i++) {
        //     res.push_back(heap.top().second);
        //     heap.pop();
        // }

        // return res;
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({p.second, p.first});
        }
        // sort(arr.rbegin(), arr.rend());
        sort(arr.begin(), arr.end(), greater<>());
                
        for(auto n : arr) {
            cout << n.first << "ha"<< n.second << endl;
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};
