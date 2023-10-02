class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int i= 0;
        int c= 0;
        int n= nums.size();
        if(is_sorted(nums.begin(), nums.end())) return 0;
        while(i<n){
            int temp= nums[n-1];
            nums.pop_back();
            nums.insert(nums.begin(), temp);
            c++;
            if(is_sorted(nums.begin(), nums.end())) return c;
            i++;
        }
        return -1;
    }
};