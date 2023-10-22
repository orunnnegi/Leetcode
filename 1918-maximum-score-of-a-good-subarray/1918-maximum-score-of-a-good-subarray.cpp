class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], i = k, j = k, mn = nums[k];
        while(i>0 || j<nums.size()-1){
            if(i>0&&j<nums.size()-1){
                if(nums[i-1]>=nums[j+1])i--;
                else j++;
            }
            else if(i==0&&j<nums.size()-1){
                j++;
            }
            else if(j == nums.size()-1 && i>0){
                i--;
            }
            mn = min(mn,min(nums[i],nums[j]));
            ans = max(ans,(j-i+1)*mn);
        }
        return ans;
    }
};