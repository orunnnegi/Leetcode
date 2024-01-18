class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int x = 0;
        for(auto &it  : nums)
        {
            x = x ^ it;
        }
        return x;
    }
};