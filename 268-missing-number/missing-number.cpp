class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        int actualSum = size * (size + 1) / 2;
        for(auto it : nums)
        {
            sum+= it;
        }
        return actualSum - sum;
    }
};