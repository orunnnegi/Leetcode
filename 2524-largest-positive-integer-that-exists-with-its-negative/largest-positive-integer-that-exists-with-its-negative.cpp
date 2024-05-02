class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = n-1;

        int ans = -1;

        while(left<right){
            if((-1)*(nums[left])==nums[right]){
                ans = nums[right];
                break;
            }
            else if(abs(nums[left])<nums[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};