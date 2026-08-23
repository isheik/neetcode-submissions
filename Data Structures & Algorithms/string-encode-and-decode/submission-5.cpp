class Solution {
public:
    // string str = "";
    string encode(vector<string>& strs) {
        string str = "";
        if(strs.size() == 0) {
            str = "";
            return "";
        }

        for(string s : strs) {
            str += s + ":DEL:";
        }
        
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs = {};

        if(s.size() == 0) {
            return {};
        }

        while(s.find(":DEL:") != -1) {
            int index = s.find(":DEL:");
            string s1 = s.substr(0, index);
            s.erase(0, index+5);
            strs.push_back(s1);
        }

        return strs;
    }
};
