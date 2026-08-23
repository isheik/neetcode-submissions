class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    int minval = numeric_limits<int>::max();

    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        minval = min(minStack.empty() ? val : minStack.back(), val);
        minStack.push_back(minval);
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
