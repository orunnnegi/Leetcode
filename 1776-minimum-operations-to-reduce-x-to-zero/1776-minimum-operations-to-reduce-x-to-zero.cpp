class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size();
            int t = 0;
            for (auto x: nums) t += x;
            t -= x;
            if (t == 0) return n;
            if (t < 0) return -1;
            int i = 0, j = 0, sum = 0, c = -1;
            while (j < n)
            {
                sum += nums[j];
                while (sum > t)
                {
                    sum -= nums[i];
                    i++;
                }
                if (sum == t)
                {
                    c = max(c, j - i + 1);
                }
                j++;
            }
            return (c == -1) ? -1 : n - c;
        }
};