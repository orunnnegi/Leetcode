class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n= nums.size();
        int c= 1;
        if(n<=2){
            return nums[0];
        }
        int ans= 0;
        for(int i= 0; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
                if(c>n/4){
                    ans= nums[i];
                    c=1;
                    break;
                }
                else{
                    c=1;
                    continue;
                }
            }
            else{
                c++;
            }
        }
        if(c>n/4) ans= nums[n-1];
        return ans;
    }
};