class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i= 0; i < size; i++)
        {
            if(nums[i] % 2 == 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;

            }
        }
         unordered_map <int , int> mpp;
        int ans= 0;
        int prefixSum = 0;
        mpp[0] =1;
        for(int i= 0; i<size; i++)
        {   prefixSum+= nums[i];
            int remaining = prefixSum - k;
            ans+= (mpp[remaining]);
            mpp[prefixSum]++;
        }   
        return ans;
        // return 0;
    }
};