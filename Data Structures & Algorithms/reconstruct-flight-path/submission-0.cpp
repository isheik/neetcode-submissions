class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // how to decide start?
        // Start is the from_i which does not point in any
        // tickets' to_i
        // End is opposite, so a ticket with to_i which is not
        // specified in any other from_i
        // => not necessarily, if the itinery has
        // a round trip part

        unordered_map<string, vector<string>> adj;
        for(auto& ticket:tickets) {
            adj[ticket[0]];
        }

        sort(tickets.begin(), tickets.end());
        for(auto& ticket:tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res = {"JFK"};
        dfs("JFK", res, adj, tickets.size()+1);
        return res;
    }

private:
    bool dfs(const string& src, vector<string>& res,
        unordered_map<string, vector<string>>& adj, int targetLen) {
            if(res.size() == targetLen) {
                return true;
            }

            if(adj.find(src) == adj.end()) {
                return false;
            }

            vector<string> temp = adj[src];
            for(int i = 0; i<temp.size(); i++) {
                // get dests for the src
                string v = temp[i];
                // delete the chosen dest
                adj[src].erase(adj[src].begin() + i);
                res.push_back(v); // put to res temporarily
                if(dfs(v, res, adj, targetLen)) return true;
                adj[src].insert(adj[src].begin() + i, v);
                res.pop_back();

            }
            return false;
        }
};
