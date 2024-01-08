class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector< int >> allTriplets;
        int size = nums.size();
        // to sort the input array and for each distinct element i need to find the sum that sums up with the element to give 0
        // a + b + c = 0
        // b + c = -a

        // for each element i need to find the sum which is equal to -(that element)
        // and since the array is sorted i can very well use 2 pointer approach here

        // [ -1, -1, -1 , 0, 1, 2]

        // 

        sort(nums.begin() , nums.end());
        for(int index = 0 ; index < size-2 ; index++)
        {
            if(index == 0 or (index > 0 and nums[index] != nums[index-1]))
            {
            int targetToSearch = -1 * (nums[index]);
            int leftIndex = index + 1;
            int rightIndex = size - 1;
            while(leftIndex < rightIndex)
            {   
                int summation = nums[leftIndex] + nums[rightIndex];
                if(summation == targetToSearch)
                {
                    allTriplets.push_back({nums[index], nums[leftIndex], nums[rightIndex]});
                    leftIndex++;
                    rightIndex--;
                    while(leftIndex < rightIndex and nums[leftIndex] == nums[leftIndex-1])
                    {
                        leftIndex++;
                    }
                    while(leftIndex < rightIndex and nums[rightIndex] == nums[rightIndex+1])
                    {
                        rightIndex--;
                    }

                }
                else if(summation < targetToSearch)
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