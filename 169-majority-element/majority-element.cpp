class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <  int , int >  mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int targetFreq= n/2;
        for(auto &[a, b] : mpp){
            if(b > targetFreq)
            {
                return a;
            }
        }
        return 0;
    }
};