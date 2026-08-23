class Solution {
public:
    bool isPalindrome(string s) {
        int head=0;
        int tail=s.size()-1;

        while(head<tail) {   
            // if(head == tail) continue;
            while(head<tail && !alphaNum(s[head])) head++;
            while(tail>head && !alphaNum(s[tail])) tail--;

            if(tolower(s[head]) != tolower(s[tail])) return false;

            head++;
            tail--;
        }

        return true;
        
    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || 
                c >= 'a' && c <= 'z' || 
                c >= '0' && c <= '9');
    }
};
