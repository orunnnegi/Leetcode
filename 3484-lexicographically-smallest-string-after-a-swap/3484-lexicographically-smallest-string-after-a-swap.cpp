class Solution {
public:
    string getSmallestString(string s) {
         int n = s.length();
    
    // Iterate through the string to find pairs to swap
    for (int i = 0; i < n - 1; ++i) {
        // Check if adjacent digits have the same parity
        if ((s[i] - '0') % 2 == (s[i+1] - '0') % 2) {
            // Swap if the current digit is greater than the next one
            if (s[i] > s[i+1]) {
                swap(s[i], s[i+1]);
                return s; // Return early after one valid swap
            }
        }
    }
    
    return s;
    }
};