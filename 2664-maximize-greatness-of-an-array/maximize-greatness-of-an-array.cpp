class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        // set<int> st;
        // for(int it : nums)
        // {
        //     st.insert(it);
        // }
        // int n = st.size();
        // map<int, int> mpp;
        // for(auto it : nums)
        // {
        //     mpp[it]++;
        // }
        // vector<int> temp(st.begin(), st.end());
        // int ans = 0;
        // int next = 0;
        // for(int ind = 0; ind < n - 1; ind++)
        // {
        //     next = ind + 1;
        //     int curr = temp[ind];
        //     int req = mpp[curr];
        //     while(req > 0 and next < n)
        //     {
        //         int check = mpp[temp[next]];
        //         if(req >= check)
        //         {
        //             ans+= check;
        //             mpp[temp[next]] = 0;
        //             next++;
        //         }
        //         else
        //         {
        //             ans+= req;
        //             mpp[temp[next]] = check - req;
        //             req = 0;
        //         }
        //     }
        // }
        // return ans;

        int left = 0;
        int right = 0;
        while(size > right)
        {
            if(nums[left] < nums[right])
            {
                ans++;
                left++;
            }
            right++;
        }
        return ans;
        
    }
};