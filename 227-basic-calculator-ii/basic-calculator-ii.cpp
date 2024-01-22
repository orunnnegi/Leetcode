class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        char sign = '+';
        int num = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if (i + 1 == s.length() || c == '+' || c == '-' || c == '*' || c == '/') {
                if (sign == '+') {
                    stack.push(num);
                } else if (sign == '-') {
                    stack.push(-num);
                } else if (sign == '*') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * num);
                } else if (sign == '/') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / num);
                }
                
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};