class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long patches = 0, maxReach = 0;
        int i = 0;

        while (maxReach < n) {
            if (i < nums.size() && maxReach + 1 >= nums[i]) {
                maxReach += nums[i];
                i++;
            } else {
                patches++;
                maxReach += (maxReach + 1);
            }
        }

        return patches;
    }
};