class Solution {
public:
    int kthGrammar(int n, int k) {
        auto stack = std::stack<char>();
        while (n != 1) {
            stack.push((k % 2 != 0) ? 's' : 'o');
            k = std::ceil(k / 2.0);
            n -= 1;
        }

        int res = 0;
        while (!stack.empty()) {
            if (stack.top() == 'o')
                res = 1 - res;
            stack.pop();
        }
        return res;
    }
};