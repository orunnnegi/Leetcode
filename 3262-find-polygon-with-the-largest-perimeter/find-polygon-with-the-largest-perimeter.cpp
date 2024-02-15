class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long size = nums.size();
        long long ans  = -1;
        long long summation = 0;
        sort(nums.begin(), nums.end());
        for(int ind = 0; ind < size; ind++)
        {
            if(ind >= 2 and nums[ind] < summation)
            {
                ans = nums[ind] + summation;
            }
            summation+= nums[ind];
        }
        return ans;
    }
};