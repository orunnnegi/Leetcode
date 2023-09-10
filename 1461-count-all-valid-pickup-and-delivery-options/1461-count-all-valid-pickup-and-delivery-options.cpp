class Solution {
public:
    const int mod= 1e9+7;
    int countOrders(int n) {
        long long res= 1;
        for(int i= n*2; i>1; i-=2){
            int numberOfPairs= ((i*(i-1))%mod)/2;
            res= (1ll*res*numberOfPairs)%mod;
        }
        return res;
    }
};