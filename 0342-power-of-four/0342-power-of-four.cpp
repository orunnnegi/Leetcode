class Solution {
public:
double loggings(int a, int b){
        return log2(a)/log2(b);
    }

    bool isPowerOfFour(int n) {
        if(n==0) return false;
        // cout<<loggings(n, 3)<<endl;
        // cout<<ceil(loggings(n, 4))<<" "<<floor(loggings(n, 3));
        if(ceil(loggings(n, 4))==floor(loggings(n, 4))) return true;
        return false;
    }
};