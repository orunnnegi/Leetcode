#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n, 0);
        stack<array<int,2>> st;
        st.push({temperatures[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[i] >= st.top()[0])
                st.pop();

            if (!st.empty())
                ans[i] = st.top()[1] - i;

            st.push({temperatures[i], i});
        }
        return ans;
    }
};
