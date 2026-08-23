class MinStack {
private:
    stack<int> st;
    stack<int> ms;
    int m;
public:
    MinStack() {
        m = numeric_limits<int>::max();
    }
    
    void push(int val) {
        st.push(val);
        ms.push(ms.empty() ? val : min(val, ms.top()));
    }
    
    void pop() {
        st.pop();
        ms.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
