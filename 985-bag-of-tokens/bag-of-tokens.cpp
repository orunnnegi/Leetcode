class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size() , score = 0 ;
        int i = 0 , j = n-1;
        int mx_sc=0;
        sort ( tokens.begin(),tokens.end() );
        while ( i<=j )
        {
           if ( tokens[i]<=power )
           {
               power = power - tokens[i];
               score ++;
               i++;
               mx_sc = max(score,mx_sc);
           }
           else if ( score>0 )
           {
               power =power + tokens[j];
               score --;
               j--;
           }
           else break;
        }
        return mx_sc;
    }
};