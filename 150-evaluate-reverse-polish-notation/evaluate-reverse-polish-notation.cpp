class Solution {
public:

void helper(stack<string> &st, string s)
{
    string a = st.top();
    st.pop();
    string b = st.top();
    st.pop();
    int res = 0;
    if(s == "+")
    {
        res = stoi(b) + stoi(a);
    }
    else if(s == "-")
    {
        res = stoi(b) - stoi(a);
    }
    else if(s == "*")
    {
        res = stoi(b) * stoi(a);
    }
    else
    {
        res = stoi(b) / stoi(a);
    }
    st.push(to_string(res));

    return ;
}
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int size = tokens.size();
        for(int ind = 0; ind < size; ind++)
        {
            // cout << tokens[ind] << " ";
            
            if(tokens[ind] == "+" or tokens[ind] == "-" or tokens[ind] == "*" or tokens[ind] == "/" )
            {
                helper(st, tokens[ind]);
            }
            
            else
            {
                st.push(tokens[ind]);
            }
        }
        // while(!st.empty())
        // {
        //     cout << st.top() << " ";
        //     st.pop();
        // }
        return stoi(st.top());
    }
};