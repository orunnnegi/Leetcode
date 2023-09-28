class Solution {
public:
    int commonFactors(int a, int b) {
        int g= __gcd(a, b);
        int c= 0;
        for(int i= 1; i<= g; i++){
            if(a%i + b%i==0) ++c;
        }
        return c;
    }
};