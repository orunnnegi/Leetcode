class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int prefixSum = 0;
        unordered_map<int , int> prefixMap;
        prefixMap[0] = 1;
        int ans = 0;
        for(int i = 0; i < size; i++)
        {
            prefixSum+= nums[i];
            int remaining = prefixSum - k;
            ans+= prefixMap[remaining];
            prefixMap[prefixSum]++;

        }
        return ans;
    }
};