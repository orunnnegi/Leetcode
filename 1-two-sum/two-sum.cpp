class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*

        Brute Force:- tc= O(n^2) sc= O(1)

        int n= nums.size();
        for(int i= 0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(nums[i]+nums[j]== target){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
        */

        int n= nums.size();
        unordered_map< int, int > mpp;
        for(int i= 0; i<n; i++){
            int remaining= target- nums[i];
            cout<<remaining<<" ";
            if(mpp[remaining]){
                return {mpp[remaining]-1, i};
            }
            mpp[nums[i]]= i+1;
        }
        return {-1 , -1};

    }
};