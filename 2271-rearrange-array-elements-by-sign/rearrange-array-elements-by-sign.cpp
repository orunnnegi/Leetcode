class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Brute force
        // int size = nums.size();
        // vector < int > positives;
        // vector < int > negatives;
        // vector < int > resultantArray(size);
        
        // for(int index = 0; index < size; index++)
        // {
        //     if(nums[index] < 0)
        //     {
        //         negatives.push_back(nums[index]);
        //     }
        //     else
        //     {
        //         positives.push_back(nums[index]);
        //     }
        // }
        // int negativeIterator = 0;
        // int positiveIterator = 0;
        // for(int index = 0; index < size; index++)
        // {
        //     if(index % 2 == 0)
        //     {
        //         resultantArray[index] = positives[positiveIterator++];
        //     }
        //     else
        //     {
        //         resultantArray[index] = negatives[negativeIterator++];
        //     }
        // }
        // return resultantArray;

        int size = nums.size();
        vector < int > resultantArray (size);
        int positiveIndex = 0;
        int negativeIndex = 1;
        for(int index = 0; index < size ; index++)
        {
            if(nums[index] >= 0)
            {
                resultantArray[positiveIndex] = nums[index];
                positiveIndex+= 2;
            }
            else
            {
                resultantArray[negativeIndex] = nums[index];
                negativeIndex+= 2;
            }
        }
        return resultantArray;


    }
};