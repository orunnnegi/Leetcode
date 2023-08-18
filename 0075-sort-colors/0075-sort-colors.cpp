class Solution {
public:
    void sortColors(vector<int>& nums) {
       int countZero=0, countOne=0, countTwo=0;
       int n= nums.size();
       for(int i= 0; i< n; ++i){
           if(nums[i]==0) ++countZero;
           else if(nums[i]==1) ++countOne;
           else ++countTwo;
       }
       cout<<countZero<<" "<<countOne<<" "<<countTwo;
       for(int i= 0; i<n; i++){
           if(i<countZero){
               nums[i]=0;
           }
           else if(i>=countZero && i<(countZero+countOne)){
               nums[i]=1;
           }
           else nums[i]=2;
       } 
    }
};