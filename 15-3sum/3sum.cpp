class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector < vector <int> > allTriplets;
        sort(nums.begin(), nums.end());
        for(int index = 0; index < size ; index++)
        {
            // a + b + c = 0;
            // b + c = -a
            if(index == 0 or (index > 0 and (nums[index] != nums[index-1])))
            {
                int target = -1 * nums[index];
            int leftIndex = index + 1;
            int rightIndex = size - 1;
            while( leftIndex < rightIndex )
            {
                
                int summation = nums[leftIndex] + nums[rightIndex];
                if(summation == target)
                {
                    allTriplets.push_back({nums[index], nums[leftIndex], nums[rightIndex]});
                    leftIndex++;
                    rightIndex--;
                    while(leftIndex < rightIndex and (nums[leftIndex] == nums[leftIndex-1]))
                    {
                        leftIndex++;
                    }
                    while(leftIndex < rightIndex and (nums[rightIndex] == nums[rightIndex+1]))
                    {
                        rightIndex--;
                    }
                }
                else if(summation < target)
                {
                    leftIndex++;
                }
                else
                {
                    rightIndex--;
                }
            }
            }
            
        }
        return allTriplets;
    }
};