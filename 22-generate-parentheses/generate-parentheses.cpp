class Solution {
public:
    void PrintP(int open, int close, vector<string> &ans, string s, int n){
        // as we are doing by recursion
        // base condition
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            PrintP(open+1, close, ans, s + "(",n);
        }
        if(close < n && close < open){
            PrintP(open, close+1, ans, s+")",n);
        }
    }

    vector<string> generateParenthesis(int n) {
        // this is a pure recursion qs
        // where we have to print all the well-formed parentheses just like printing
        // all the subseq
        // using backtracking 
        vector<string> ans;
        PrintP(0,0,ans,"",n);

        return ans;
    }
};