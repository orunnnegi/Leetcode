#include<bits/stdc++.h>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi= INT_MIN;
        int c= 0;
        for(int i= 0; i<nums.size();i++){
            if(nums[i]==1) c++;
            if(nums[i]==0){
                maxi= max(maxi, c);
                c=0;
            }
            cout<< c<< " ";
        }
        return max(maxi, c);
        
    }
};