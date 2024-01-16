class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int length = 0;
        int temp = 0;
        for(int i = 0; i < size; i++)
        {
            if(nums[i] == 1)
            {
                temp++;
            }
            else
            {
                length = max(length, temp);
                temp = 0;
            }
        }
        return max(length , temp);
    }
};