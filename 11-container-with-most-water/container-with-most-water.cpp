class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = INT_MIN;
        while(left != right)
        {
            ans = max(ans, (min(height[left], height[right]) * abs(left - right)));
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};