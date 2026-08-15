class MinStack {
    stack<long long> st;
    long long mini = LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
        {
            st.push(value);
            mini = value;
        }
        else if(value>=mini)
        {
            st.push(value);
        }
        else
        {
            st.push(2LL*value-mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty())
        {
            return;
        }
        if(st.top() < mini)
        {
            mini = 2LL*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())
        {
            return -1;
        }
        if(st.top() < mini)
        {
            return (int)mini;
        }
        else
        {
            return (int)st.top();
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */