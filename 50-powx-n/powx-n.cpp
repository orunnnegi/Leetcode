class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = abs(n);
        while(power > 0)
        {
            if(power % 2 == 1)
            {
                ans = ans * x;
                power = power - 1;
            }
            else
            {
                x = x * x;
                power = power / 2;
            }
        }
        if(n < 0)
        {
            return (double)(1.0)/(double)(ans);
        }
        return ans;
    }
};