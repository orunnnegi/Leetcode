class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        if(n<3) return 0;
        int ans= 0;
        int c= 0;
        for(int i = 1; i < n-1; i++)
        {
            if(nums[i]-nums[i-1] == nums[i+1]-nums[i])
            {
                ans+= (c+1);
                c++;
            }
            else{
                c=0;
            }
        }
        return ans;
    }
};