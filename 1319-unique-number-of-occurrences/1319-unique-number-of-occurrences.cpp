class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        set<int> s;
        for(auto it: arr) ++mpp[it];
        for(auto it: mpp) s.insert(it.second);
        if(mpp.size()==s.size()) return true;
        return false;
    }
};