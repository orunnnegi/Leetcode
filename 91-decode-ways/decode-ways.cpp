class Solution {
private:
    unordered_map<int, int> map;

    int helper(const string& s, int i) {
        if (i >= s.length()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (map.count(i)) {
            return map[i];
        }
        int ways = helper(s, i + 1);
        if (i + 1 < s.length() && stoi(s.substr(i, 2)) <= 26) {
            ways += helper(s, i + 2);
        }
        map[i] = ways;
        return ways;
    }

public:
    int numDecodings(string s) {
        return helper(s, 0);
    }
};