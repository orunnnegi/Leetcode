class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==INT_MIN || n==0) return false;
        // string str= bitset<32>(n).to_string();
        // int count= 0;
        // for(int i= 0; i<32; i++){
        //     if(str[i]=='1') count++;
        // }
        // if(count==1) return true;
        // return false;
        if(ceil(log2(n))==floor(log2(n))) return true;
        return false;
    }
};