class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int , int> mpp;
        int ans= 0;
        int prefixSum = 0;
        mpp[0] =1;
        for(int i= 0; i<n; i++)
        {   prefixSum+= nums[i];
            int remaining = prefixSum - k;
            ans+= (mpp[remaining]);
            mpp[prefixSum]++;
        }   
        return ans;
    }
};