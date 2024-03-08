class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0);
        for(int num : nums)
        {
            freq[num]++;
        }
        int ans = 0;
        maxi = *max_element(freq.begin(), freq.end());
        for(int it : freq)
        {
            if(it == maxi)
            {
                ans+= it;
            }
        }
        return ans;
    }
};