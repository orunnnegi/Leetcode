class Solution {
public:
    string reverseParentheses(string s) {
        deque<char> primaryStack, helperQueue;
        for (char chr : s) {
            if (chr != ')') {
                primaryStack.push_back(chr);
            } else {
                while (primaryStack.back() != '(') {
                    helperQueue.push_back(primaryStack.back());
                    primaryStack.pop_back();
                }
                primaryStack.pop_back();
                while (!helperQueue.empty()) {
                    primaryStack.push_back(helperQueue.front());
                    helperQueue.pop_front();
                }
            }
        }
        string res;
        while (!primaryStack.empty()) {
            res.push_back(primaryStack.front());
            primaryStack.pop_front();
        }
        return res;
    }
};