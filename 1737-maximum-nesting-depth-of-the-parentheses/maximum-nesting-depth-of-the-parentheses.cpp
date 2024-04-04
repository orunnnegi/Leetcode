class Solution {
public:
    int maxDepth(string s) {
        int b=0;
        int depth=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
               b++;
            }
            if(depth<b){
               depth=b; 
            }
          
            if(s[i]==')' && b>0){
              b--;
            }
        }
        return depth;
    }
};