class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> check;
        for(int i = 0; i < size; i++)
        {
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
            {
                check.push(s[i]);
            }
            else
            {
                if(check.empty() == true)
                {
                    return false;
                }
                char topMost = check.top();
                check.pop();
                if(topMost == '(' and s[i] == ')' or topMost == '[' and s[i] == ']' or  topMost == '{' and s[i] == '}'){
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return check.empty() ? true : false;
    }
};