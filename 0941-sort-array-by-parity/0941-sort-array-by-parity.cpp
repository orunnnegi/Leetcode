class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        int j= 0, k=  n-1;
        vector<int> ans(n);
        for(int i= 0; i<n; i++){
            if(nums[i]&1) ans[k--]= nums[i];
            else ans[j++]= nums[i];
        }
        return ans;
    }
};