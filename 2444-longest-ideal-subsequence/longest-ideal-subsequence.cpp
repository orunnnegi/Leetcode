class Solution {
public:
    int longestIdealString(string s, int k) {
        int arr[26] = {0}, result = 0;
        int a = 0, b = 25;
        for (int i = 0; i < s.length(); i++) {
            a = 0, b = 25;
            int l = s[i] - 'a';
            a = max(a, l - k);
            b = min(b, l + k);
            int max = 0;
            while (a <= b) {
                if (arr[a] > max)
                    max = arr[a];
                a++;
            }
            arr[l] = max + 1;
            if (arr[l] > result)
                result = arr[l];
        }
        return result;
    }
};