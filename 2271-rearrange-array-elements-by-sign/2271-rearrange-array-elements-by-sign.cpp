class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n); 
        int j=0; int k=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                res[j]= nums[i]; j+=2;
            }
            else{
                res[k]= nums[i]; k+=2;
            }
        }
        return res;
    }
};