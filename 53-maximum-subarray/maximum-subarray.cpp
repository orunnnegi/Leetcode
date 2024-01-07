class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int n = nums.size();
        // int maxSum = INT_MIN;
        // for(int i = 0; i<n ; i++)
        // {
        //     int currSubarraySum = 0;
        //     for( int j = i ; j < n ; j++)
        //     {
        //         currSubarraySum+= (nums[j]);
        //         maxSum = max( maxSum , currSubarraySum );
        //     }
        // }
        // return maxSum;

        int n = nums.size();
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i = 1; i < n; i++)
        {
            currSum = max(currSum + nums[i] , nums[i]);
            maxSum = max(currSum , maxSum);
        }
        return maxSum;

    }
};