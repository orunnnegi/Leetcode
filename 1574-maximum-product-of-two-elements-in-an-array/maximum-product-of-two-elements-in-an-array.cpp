class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();

        if(n==2) return (nums[0]-1) * (nums[1]-1);
        return (nums[n-1]-1) * (nums[n-2]-1);
    }
};