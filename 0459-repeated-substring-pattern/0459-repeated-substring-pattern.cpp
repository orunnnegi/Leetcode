class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        for(int i=1;i<=s.size()/2;i++){
            string x=s.substr(0,i);
            if(x+s==s+x)
            return true;
        }
        return  false;
    }
};