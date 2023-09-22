class Solution {
public:
    bool isSubsequence(string s, string t) {
        int textsize= t.length(), patternsize= s.length();
        if(patternsize==0 && textsize!=0) return true;
        if(patternsize==0 && textsize==0) return true;
        // if(textsize==0 || patternsize==0) return false;
        // cout<<textsize<<" "<<patternsize;
        
        // if(textsize==0) return false;
        
        vector<bool> check(patternsize, false);
        int k= 0;
        for(int i= 0; i<textsize; i++){
            if(t[i]==s[k]){
                // cout<<
                check[k]=true;
                k++;
            }
        }
        if(!check[patternsize-1]) return false;
        return true;
    }
};