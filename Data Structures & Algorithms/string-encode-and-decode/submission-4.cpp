class Solution {
public:
    string str = "";
    string encode(vector<string>& strs) {
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

        while(str.find(":DEL:") != -1) {
            int index = str.find(":DEL:");
            string s = str.substr(0, index);
            str.erase(0, index+5);
            strs.push_back(s);
        }

        return strs;
    }
};
