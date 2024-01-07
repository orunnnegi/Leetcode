class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map <  int , int >  mpp;
        // for(auto it: nums){
        //     mpp[it]++;
        // }
        // int targetFreq= n/2;
        // for(auto &[a, b] : mpp){
        //     if(b > targetFreq)
        //     {
        //         return a;
        //     }
        // }
        // return 0;
        int n= nums.size();
        int element= 0;
        int count= 0;
        for(int i= 0; i<n; i++){
            if(count==0){
                element= nums[i];
                count= 1;
                continue;
            }
            else{
                if(element== nums[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return element;
    }
};