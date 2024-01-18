class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int size = nums.size();
        for(; i < size ; i++)
        {
            if(nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        while(j < size)
        {
            nums[j++] = 0;
        }
        return;
    }
};