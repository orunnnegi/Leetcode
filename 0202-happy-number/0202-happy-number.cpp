class Solution {
public:
    int helper(int n){
        int s= 0;
        while(n!=0){
            int rem= n%10;
            s= s+(rem*rem);
            n/=10;
        }
        return s;
    }

    bool isHappy(int n) {
        if(n==1 || n== 7) return true;
        map<int, int> mpp;
        int sum = n;
        while(true){  
            if(sum==1 || sum==7) return true;
            else if(mpp[sum]) break;
            else mpp[sum]++;
            sum= helper(sum);
        }
        return false;
    }
};