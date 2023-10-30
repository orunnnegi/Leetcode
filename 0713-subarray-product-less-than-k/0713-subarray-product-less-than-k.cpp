class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n= nums.size();
        int left = 0; int right= 0; int prod= nums[right]; int count = 0;
        while(left<n && right < n){
            // prod= prod*nums[right];
            if(prod<k){
                right++;
                if(right>=left){
                    count = count+(right-left);
                }
                if(right<n){
                    prod= prod*nums[right];
                }
            }
            else{
                if(nums[left]!=0) prod/= nums[left];
                left++;
            }

            // cout<<prod<<" "<<count;
        }   
        return count;
    }
};