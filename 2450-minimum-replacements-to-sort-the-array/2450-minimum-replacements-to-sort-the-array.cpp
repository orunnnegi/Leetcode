class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int last=nums[n-1];     
        for(int i=n-2; i>=0; i--){
            if(nums[i]>last){
                if(nums[i]%last==0){
                    int x=nums[i]/last;
                    ans+=(x-1);
                }
                else{
                    int x=nums[i]/last;
                    ans+=x;
                    last=nums[i]/(x+1);
                }
            }
            else last=nums[i];
        }
        return ans;
    }
};