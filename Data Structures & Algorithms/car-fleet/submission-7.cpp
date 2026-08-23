class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // ゴールに近い順にソート（降順）
        sort(cars.rbegin(), cars.rend());

        stack<double> s;  // 到着時間を管理する stack

        for (auto &car : cars) {
            double time = (double)(target - car.first) / car.second;

            // 後ろの車が先頭フリートに追いつく場合は新フリートにしない
            if (!s.empty() && time <= s.top()) {
                // 追いつくので push しない
                continue;
            }

            s.push(time);  // 新しいフリートを作る
        }

        return s.size();
    }
};
