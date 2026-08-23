class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        int c = 0;

        while(l<=r) {
            while(l<r && !isalnum(s[l])) l++;
            while(r>l && !isalnum(s[r])) r--;

           // if(l>r) return true;

            if(tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }

        return true;
    }
};
