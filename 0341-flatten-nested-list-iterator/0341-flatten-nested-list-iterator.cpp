/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; i--){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = st.top().getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        while(!st.empty()){
            NestedInteger c = st.top();
            if(c.isInteger())
                return true;
            
            st.pop();
            vector<NestedInteger> & v = c.getList();
            int size = v.size();
            for(int i = size - 1; i >= 0; i--)
                st.push(v[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */