class MinStack {
public:
    stack<pair<int  , int>> store;

    MinStack() {
        
    }
    
    void push(int val) {
        if(store.empty() == true)
        {
            store.push({val, val});
        }
        else
        {
            int temp = store.top().second;
            int s = temp > val ? val : temp;
            store.push({val , s});
        }
    }
    
    void pop() {
        store.pop();
    }
    
    int top() {

        return store.top().first;
    }
    
    int getMin() {
        return store.top().second;
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