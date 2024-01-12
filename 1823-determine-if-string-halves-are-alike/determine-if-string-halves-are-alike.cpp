class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if((s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] =='A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') and (i < (n/2)))
            {
                count = count + 1;
            }
            if((s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] =='A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') and (i >= (n/2)))
            {
                count--;
            }
            // cout << count <<" ";
        }
        return count == 0;
    }
};