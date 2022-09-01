class MinStack {
private:
    vector< pair<int, int> > st;
public:
    MinStack()
    {
        st.clear();
    }
    
    void push(int val)
    {
        if(st.empty())
        {
            st.push_back({val, val});
        }
        else
        {
            st.push_back({val, min(val, st.back().second)});
        }
    }
    
    void pop()
    {
        if(!st.empty())
            st.pop_back();
    }
    
    int top()
    {
        return st.back().first;
    }
    int getMin()
    {
        return st.back().second;
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
