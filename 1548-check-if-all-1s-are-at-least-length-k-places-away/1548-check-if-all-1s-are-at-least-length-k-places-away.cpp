class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        int n= nums.size();
        bool one = false;
        for(int i= 0; i<n; i++){
            if(nums[i]==1 && one==false){
                one= true;
                continue;
            }
            if(nums[i]== 0){
                count++;
            }
            else if(nums[i]==1 && one==true){
                if(count<k)
                return false;
                else count=0;
            }
        }
        return true;
    }
};