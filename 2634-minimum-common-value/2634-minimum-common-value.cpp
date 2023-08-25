class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for(auto it: nums1) ++mpp[it];
        set<int> s;
        for(auto it: nums2){
            if(mpp[it]) s.insert(it);
        }
        if(s.size()==0) return -1;
        return *s.begin();
    }
};