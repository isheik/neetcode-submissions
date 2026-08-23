class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(char c:s) {
            if(c == ')' || c == ']' || c == '}') {
                if(stack.size() < 1) return false;

                char top = stack.top();
                stack.pop();
                switch(c) {
                    case ')':
                        if(top != '(') return false;
                        break;
                    case ']':
                        if(top != '[') return false;
                        break;                        
                    case '}':
                        if(top != '{') return false;
                        break;
                    default:
                        break;
                }

            } else {
                stack.push(c);
            }
        }

        return stack.size() == 0;
    }
};
