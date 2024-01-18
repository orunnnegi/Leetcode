class Solution {
public:
    void helper(int open , int close , vector<string> &generation, string s, int total)
    {
        if(open == total and close == total)
        {
            generation.push_back(s);
            return;
        }
        if(open < total)
        {
            helper(open + 1, close , generation, s+"(", total);
        }
        if(close < total and close < open)
        {
            helper(open, close + 1, generation, s+")", total);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> generation;
        helper(0, 0, generation, "", n);
        return generation;
    }
};