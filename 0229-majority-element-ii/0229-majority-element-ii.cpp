class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Brute force
        map<int, int> mpp;
        for(auto it: nums) ++mpp[it];
        vector<int> ans;
        int n= nums.size();
        for(auto it: mpp){
            if(it.second>n/3) ans.push_back(it.first);
        }
        return ans;
    }
};