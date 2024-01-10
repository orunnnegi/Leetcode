class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin() , nums.end());
        int closestSum = 0;
        int miniDiff = INT_MAX;
        int miniSum = 0;
        for(int index = 0; index < size - 2; index++)
        {
            int left = index + 1;
            int right = size - 1;
            while(left < right)
            {
                int remaining = nums[left] + nums[right];
                int totalSum = remaining + nums[index];
                int currDiff = abs(totalSum - target);
                if(currDiff < miniDiff)
                {
                    miniDiff = currDiff;
                    miniSum = totalSum;
                }
                if(totalSum < target)
                {
                    left++;
                }
                else if(totalSum == target)
                {
                    left++;
                    right--;
                }
                else
                {
                    right--;
                }
            }
        }
        return miniSum;
    }
};