class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int size = nums.size();
        unordered_map < int, int > isPresent;
        for( int index = 0 ; index < size ; index++)
        {
            if( nums[index] <= 0 )
            {
                continue;
            }
            else
            {
                isPresent[nums[index]] = -1;
            }
        }
        int iterator = 1;
        for( int index = iterator ; index <= size+1 ;index++)
        {
            if(isPresent[index] == -1)
            {
                continue;
            }
            else
            {
                return index;
            }

        }
        return iterator;

    }
};