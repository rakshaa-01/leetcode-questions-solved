class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
       if(st.empty()) {
        st.push(val);
        mini=val;
       }
       else {
        if(val>mini) st.push(val);
        else {
            st.push(2LL*val-mini);
            mini=val;
        }
       }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x=st.top();
        st.pop();

        if(x<mini) {
            mini=2LL*mini-x;
        }
        // if (st.empty()) {
        //     mini = LLONG_MAX;
        // }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();

        if(mini<x) return x;
        return mini;
    }
    
    int getMin() {
        if(mini==LONG_MAX) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */