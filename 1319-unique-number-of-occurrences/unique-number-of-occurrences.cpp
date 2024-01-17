class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size = 0;
        unordered_map<int , int> mpp;
        int c = 0;
        unordered_set<int> st;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        vector<int> v;
        for(auto it : mpp)
        {
            v.push_back(it.second);
            st.insert(it.second);
        }
        return v.size() == st.size();
    }
};