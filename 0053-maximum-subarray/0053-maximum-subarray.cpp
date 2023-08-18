class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer= nums[0]; //Initialize the answer as the first element
        int currSum= nums[0];//Initialize the current Subarray sum as the first element
        int n= nums.size();//Calculate the size of the array
        for(int i= 1; i< n; ++i){
            currSum= max(nums[i], currSum+nums[i]);/*If the current element is greater than the sum of current element and current sum then update the current sum ans the current element*/
            answer= max(answer, currSum);//Store the greater of current sum and the answer
        }
        return answer;
    }
};