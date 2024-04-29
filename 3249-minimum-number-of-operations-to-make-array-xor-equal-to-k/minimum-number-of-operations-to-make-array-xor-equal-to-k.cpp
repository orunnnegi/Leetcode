class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),i,j=0,s=0;
        for(i=0;i<n;i++)
        {
            s^=nums[i];
        }
        
        if(s==k)
        return 0;
        int a=s^k;
        
        while(a)
        {
            j++;
            a=a&(a-1);
        }
        return j;
    }
};