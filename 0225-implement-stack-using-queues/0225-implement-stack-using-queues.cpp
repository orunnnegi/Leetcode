class MyStack {
public:
    queue<int> q;
    queue<int> hq;
    MyStack() {
    }
    
    void push(int x) {
        fun(x);
    }
    void fun(int x)
    {
       if(q.size()==0)
       {
           q.push(x);
           return;
       }
       int d =q.front();
       q.pop();
       hq.push(d);
       fun(x);
       while(!hq.empty())
       {
           q.push(hq.front());
           hq.pop();
       }
    }
    int pop() {
        int d= q.front();
        q.pop();
        return d;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */