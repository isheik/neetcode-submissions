class Solution {
    unordered_set<int> seen;
    unordered_map<int, vector<int>> adj;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
            adj[i] = {};
        }

        for(const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0; i<adj.size(); i++) {
            if(!dfs(i)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int crs) {
        if(seen.count(crs) > 0) {
            return false;
        }
        if(adj[crs].size() == 0) {
          //  seen.clear();
            return true;
        }

        seen.insert(crs);
        for(int i=0; i<adj[crs].size(); i++) {
            if(!dfs(adj[crs][i])) {
                return false;
            }
        }
        seen.erase(crs);
//        adj[crs].clear();

        return true;
    }
};
