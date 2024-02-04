class Solution {
public:
    string minWindow(string s, string t) {
        int i     = 0;
        int j     = 0;
        int tlen  = t.length();
        int win[] = { 0, INT_MAX };
        int counts['z' - 'A' + 1] = { 0 };

        for (int ch: t) {
            counts[ch - 'A']++;
        }
        while (j < s.length()) {
            if (counts[s[j] - 'A'] > 0) {
                tlen--;
            }
            counts[s[j] - 'A']--;
            j++;
            while (tlen == 0) {
                if (j - i < win[1] - win[0]) {
                    win[0] = i; win[1] = j;
                }
                counts[s[i] - 'A']++;
                if (counts[s[i] - 'A'] > 0) {
                    tlen++;
                }
                i++;
            }
        }
        return (win[1] != INT_MAX) ? s.substr(win[0], win[1] - win[0]) : "";
    }
};