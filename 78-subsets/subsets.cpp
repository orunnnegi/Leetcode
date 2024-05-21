class Solution {
public:
    void subsets(int ind, int n, vector<int> &nums, vector<vector<int>> &result, vector<int> &subset)
    {
        if(ind == n)
        {   
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        subsets(ind + 1,n, nums, result , subset);
        subset.pop_back();
        // subset.push_back();
        subsets(ind + 1, n, nums, result , subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        int n = nums.size();
        subsets(0, n, nums, result, subset);
        return result;
    }
};