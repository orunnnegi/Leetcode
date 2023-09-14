class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, int> mpp;
        for(auto it: nums) mpp[it]++;
        while(true){
            if(mpp[original]==0) break;
            else{
                original= original *2;
            }
        }
        return original;

    }
};