class Solution {
public:
    bool rotateString(string s, string goal) {
        int size = s.size();
        for(int ind = 0; ind < size; ind++)
        {
            s+= s[ind];
            string temp(s.begin() + ind + 1, s.end());
            if(temp == goal)
            {
                return true;
            }
        }
        return false;
    }
};