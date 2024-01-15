class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> maxLeft(size);
        vector<int> maxRight(size);
        maxLeft[0] = height[0];
        maxRight[size - 1] = height[size - 1];
        int ans = 0;
        for(int i = 1; i < size ; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
            maxRight[size - i - 1] = max(height[size - i - 1], maxRight[size - i]);

        }
        for(int i = 0; i < size; i++)
        {
            ans+= (min(maxRight[i], maxLeft[i]) - height[i]);
            
        }
        return ans;
    }
};