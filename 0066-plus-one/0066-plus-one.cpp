class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        vector<int> v(n);
        int add= 1;
        bool carry= false;
        for(int i= n-1; i>=0; --i){
            int sum= 0;
            if(i==n-1){
                sum= digits[i]+add;
                if(sum>9){
                    carry = true;
                    v[i]= 0;
                }
                else{
                    v[i]= sum;
                }
            }
            else{
                if(carry){
                    sum= digits[i]+carry;
                    if(sum>9){
                        v[i]=0;
                        carry= true;
                    }
                    else{
                        v[i]= sum;
                        carry= false;
                    }
                }
                else{
                    v[i]= digits[i];
                    carry= false;
                }
            }
        }
        if(carry) v.insert(v.begin(), 1);
        return v;
    }
};