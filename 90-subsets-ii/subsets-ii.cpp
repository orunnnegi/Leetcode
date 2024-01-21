class Solution {
public:

    void generateSubsets(int ind, int size, vector<int> &nums,  set<vector<int>> &allSubsets, vector<int> &temp)
    {
        if(ind == size)
        {
            allSubsets.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        generateSubsets(ind + 1, size, nums,allSubsets, temp);
        temp.pop_back();
        generateSubsets(ind + 1, size, nums, allSubsets, temp);


    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> allSubsets;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        generateSubsets(0, size, nums,allSubsets,temp);
         vector<vector<int>> subsets(allSubsets.begin(), allSubsets.end());
         return subsets;
    }
};