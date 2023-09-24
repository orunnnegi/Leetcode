class Solution {
public:
    int alternateDigitSum(int n) {
        int d= log10(n)+1;
        bool flag= true;
        if(!(d&1)) flag= false;
        int sum= 0;
        while(n>0){
            int rem= n%10;
            if(flag) {sum+= rem; flag= false;}
            else {sum+= (-1*rem); flag= true;}
            n/= 10;

        }
        return sum;
    }
};