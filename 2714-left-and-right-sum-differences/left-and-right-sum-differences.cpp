class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int> right(size , 0);
        vector<int> left(size , 0);
        vector<int> ans(size , 0);
        for(int ind = 1; ind < size ; ind++)
        {
            right[ind] = right[ind - 1] + nums[ind - 1];
            left[size - ind - 1] = left[size - ind] + nums[size -ind ]; 
        }
        for(int ind = 0; ind < size; ind++)
        {
            ans[ind] = abs(right[ind] - left[ind]);
        }

        // for(int ind = 0; ind < size; ind++)
        // {
        //     cout << left[ind] << " " << right[ind] << endl;
        // }
        return ans;
    }
};