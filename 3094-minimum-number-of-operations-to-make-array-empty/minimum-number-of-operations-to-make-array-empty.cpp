class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        map<int, int> mpp;
        for(auto it: nums) mpp[it]++;
        for(auto &[a, b]: mpp){
            if(b==1){
                return -1;
            }
        }
        int ans= 0;
        for(auto &[a,b]: mpp){
            // cout<<b<<" ";
            // int c= ceil(b/3);
            if(b%3){
                ans+= ((b/3)+1);
            }
            else ans+= (b/3);
            // cout<<c<<endl;
            // ans+= round(b/3);
        }
        return ans;
    }
};