class Solution {
public:

    const int mod = 1e9 + 7;
    long long power(long long x, long long p)
    {
        long long ans = 1;
        while(p > 0)
        {
            if(p % 2 == 1)
            {
                ans = ans * x;
                ans = ans % mod;
                p--;
            }
            else
            {
                x = x * x;
                x = x % mod;
                p = p/2;
            }
        }
        return ans;

    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        return (power(5, even)  * power(4, odd)) % mod;
    }
};