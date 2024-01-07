class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        int maxLength = 1;
        int lengthTillNow = 1;
        for(int i = 0 ; i < size-1 ; i++)
        {
            if(nums[i] + 1 == nums[i+1])
            {
                lengthTillNow++;
            }
            else if(nums[i+1] == nums[i])
            {
                continue;
            }
            else
            {
                maxLength = max(maxLength , lengthTillNow);
                lengthTillNow = 1;
            }
        }
        return max(maxLength , lengthTillNow);
    }
};