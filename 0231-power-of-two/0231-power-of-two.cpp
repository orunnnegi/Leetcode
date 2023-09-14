class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==INT_MIN) return false;
        string str= bitset<32>(n).to_string();
        int count= 0;
        for(int i= 0; i<32; i++){
            if(str[i]=='1') count++;
        }
        if(count==1) return true;
        return false;
    }
};