class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int tCharMp[256];
        int sCharMp[256];
        int freqMp[256];
        for (int i = 0; i < 256; i++) {
            sCharMp[i] = -1;
            tCharMp[i] = -1;
            freqMp[i] = 0;
        }
        for (char chr : s) {
            freqMp[chr]++;
        }
        int size = s.size();
        for (int indx = 0; indx < size; indx++) {
            char sChar = s[indx], tChar = t[indx];
            int tIndx = tChar;
            int sIndx = sChar;
            if (tCharMp[tIndx] == -1) {
                tCharMp[tIndx] = sChar;
            } else {
                if (tCharMp[tIndx] != sChar) return false;
            }
            if (sCharMp[sIndx] == -1) {
                sCharMp[sIndx] = tChar;
            } else {
                if (sCharMp[sIndx] != tChar) return false;
            }
        }
        for (char chr : t) {
            int indx = tCharMp[chr];
            if (--freqMp[indx] < 0) return false;
        }
        return true;
    }
};