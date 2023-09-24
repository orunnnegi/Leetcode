class Solution {
public:
    #define ll long long 
    
    vector<long long> findPrefixScore(vector<int>& nums) {
        
        int n= nums.size();
        vector<ll> convert(n);
        vector<ll> maximums(n);
        maximums[0]= nums[0];
        for(int i= 1; i<n; i++){
            maximums[i]= max(maximums[i-1], 1ll*nums[i]);
        }
        for(int i= 0; i<n; ++i){
            convert[i]= (1ll* nums[i])+1ll*(maximums[i]);
        }
        vector<ll> prefix(n);
        prefix[0]= convert[0];
        for(int i= 1; i<n; i++){
            prefix[i]= convert[i]+prefix[i-1];
        }
        return prefix;
        
    }
};