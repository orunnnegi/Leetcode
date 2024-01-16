class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int left = -1;
        int right = 0;
        int count = 0;
        int length = 0;
        while(right < size)
        {
            if(nums[right] == 1)
            {
                right++;
            }
            else
            {
                right++;
                count++;
            }
            while(count > k and left < right)
            {
                left++;
                if(nums[left] == 0)
                {
                    count--;
                }
            }
            length = max(length , right - left - 1);
        }
        return length;
    }
};