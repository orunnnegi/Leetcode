class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        unordered_set < int > uniques;
        for(int i = 0; i < size; i++)
        {
            uniques.insert(nums[i]);
        }
        int maxLength = 1;
        for(auto it: uniques)
        {
            if(uniques.find(it-1) == uniques.end())
            {
                int element = it;
                int currLength = 1;
                while(uniques.find(element+1) != uniques.end())
                {
                    currLength++;
                    element = element + 1;
                }
                maxLength = max(maxLength , currLength);

            }
        }
        return maxLength;
    }
};