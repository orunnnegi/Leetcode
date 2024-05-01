class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for(int ind = 0; ind < word.size(); ind++)
        {
            if(word[ind] == ch)
            {
                index = ind;
                break;
            }
        }
        reverse(word.begin(), word.begin() + (index + 1));
        return word;

    }
};